import './style.css';

import * as THREE from 'three';
import { MTLLoader } from 'three/addons/loaders/MTLLoader.js';
import { OBJLoader } from 'three/addons/loaders/OBJLoader.js';


console.clear()

// initialise some variables based on device aspect ratio
let cameraRotation = 0;
let radius = window.innerWidth;
let cameraDistance = 35;
if(devicePixelRatio > 1) {
  cameraRotation = 30;
  radius = window.innerHeight;
}

const ballMaxSize = 1 / devicePixelRatio;
const ballMinSize = 0.5 / devicePixelRatio;


console.log(devicePixelRatio)

// Set-up scene essentials: Scene, Camer, Renderer
const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(75, window.innerWidth/window.innerHeight, 0.1, 1000);   // Arguments: FoV, Aspect Ratio, View Frostrum near, View Frostrum far (View Frostrum is basically how close and far away can an object be before they aren't visible)
const renderer = new THREE.WebGL1Renderer({
  canvas: document.querySelector('#bg'),
});

renderer.setPixelRatio(window.devicePixelRatio);
renderer.setSize(window.innerWidth, window.innerHeight);
renderer.setClearColor(0xD3C7C1, 1);

camera.position.setZ(cameraDistance);
camera.position.setX(0.1);
camera.rotateZ(cameraRotation);

renderer.render(scene, camera);



// Scene Geometry
const computers = [];

const materials = [
  "ComputerBlue.mtl",
  "ComputerGreen.mtl",
  "ComputerPurple.mtl",
  "ComputerRed.mtl",
  "ComputerYellow.mtl"
];

const mtlLoader = new MTLLoader();

console.log(mtlLoader)


for(let i = 0; i < THREE.MathUtils.randFloat(40, 100); i++) {
  mtlLoader.load( materials[Math.floor(Math.random()*materials.length)], function( materials ) {

    materials.preload();
    let objLoader = new OBJLoader();
    objLoader.setMaterials( materials );
    objLoader.load( 'Computer.obj', function ( object ) {

      object.userData = {
        posY: THREE.MathUtils.randFloat(-10, 10), // at what height
        radius: THREE.MathUtils.randFloat(0.5, radius/48), // how far from Y-axis
        phase: Math.random() * Math.PI * 2, // where to start
        speed: (0.1 - Math.random() * THREE.MathUtils.randFloat(-0.2, 0.2)) * Math.PI, // how fast to circulate
        orbitPath: THREE.MathUtils.randFloat(-7, 7),
      }
        
      object.scale.setScalar(THREE.MathUtils.randFloat(ballMinSize, ballMaxSize));
      
      scene.add(object);
      computers.push(object);

    } );

});

}

// Scene Lighting
const pointLight1 = new THREE.PointLight(0xffffff)
pointLight1.position.set(30, 40, 10)

const pointLight2 = new THREE.PointLight(0xffffff)
pointLight2.position.set(-30, -40, -10)

const ambientLight = new THREE.AmbientLight(0xffffff, 0.2)

scene.add(pointLight1);
scene.add(pointLight2);
scene.add(ambientLight);

/* Helpers
const pointLightHelper = new THREE.PointLightHelper(pointLight);
const gridHelper = new THREE.GridHelper(200, 50);

scene.add(pointLightHelper,gridHelper);
*/

// Orbit contols
//const controls = new OrbitControls(camera, renderer.domElement)

let t = 0;

function scrollAnimate() {
  //const t2 = document.body.getBoundingClientRect().top;

  t += 0.02
}

document.body.onscroll = scrollAnimate;

computers.forEach(computer => {
  
  const [x, y, z] = Array(3).fill().map(() => THREE.MathUtils.randFloatSpread(100));

  computer.position.set(x, y, z);
})

document.addEventListener('mousemove', function(e){
  let sensitivity = -0.00025;
  orbit.rotateY( e.movementX * sensitivity );
  orbit.rotateX( e.movementY * sensitivity ); 
  orbit.rotation.z = 0; //this is important to keep the camera level..
})
  
//the camera rotation pivot
let orbit = new THREE.Object3D();
orbit.rotation.order = "YXZ"; //this is important to keep level, so Z should be the last axis to rotate in order...
orbit.position.copy( camera.position );
scene.add(orbit);

//offset the camera and add it to the pivot
//you could adapt the code so that you can 'zoom' by changing the z value in camera.position in a mousewheel event..
//let cameraDistance = 10;
camera.position.z = cameraDistance;
orbit.add( camera );

function animate() {
  requestAnimationFrame(animate);

  t += 0.001

  //controls.update()
  
  computers.forEach(computer => {
    let ud = computer.userData;
    let a = (ud.speed * t) + ud.phase;
    computer.position.set(Math.cos(a), 0, -Math.sin(a))
      .multiplyScalar(ud.radius)
      .setY(Math.sin(a*(ud.phase/2)) * ud.orbitPath);

      computer.rotation.set(Math.cos(a*3), 0, -Math.sin(a*7));
  });

  camera.position.x *= 1.1;

  renderer.render(scene, camera);
}

animate();