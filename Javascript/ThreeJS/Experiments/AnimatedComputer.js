import './style.css';

import * as THREE from 'three';
import {OrbitControls} from "https://cdn.jsdelivr.net/npm/three@0.127.0/examples/jsm/controls/OrbitControls.js";
import {GLTFLoader} from "three/examples/jsm/loaders/GLTFLoader.js"

//Initialize the scene
let cameraDistance = 1.5;

const gltfLoader = new GLTFLoader();
let globalMixer, scrollMixer;
const scene = new THREE.Scene();
// const camera = new THREE.PerspectiveCamera(75, window.innerWidth/window.innerHeight, 0.1, 1000);   // Arguments: FoV, Aspect Ratio, View Frostrum near, View Frostrum far (View Frostrum is basically how close and far away can an object be before they aren't visible)
const aspect = window.innerWidth / window.innerHeight;
const camera = new THREE.OrthographicCamera( - cameraDistance * aspect, cameraDistance * aspect, cameraDistance, - cameraDistance, 0.1, 100000 );
const renderer = new THREE.WebGL1Renderer({
  canvas: document.querySelector('#bg'),
});
renderer.shadowMap.enabled = true;

renderer.setPixelRatio(window.devicePixelRatio);
renderer.setSize(window.innerWidth, window.innerHeight);
renderer.setClearColor(0xD3C7C1, 1);

// Scene Lighting
// const pointLight1 = new THREE.PointLight(0xffffff);
// pointLight1.castShadow = true;
// pointLight1.position.set(20, 10, 30);

// const pointLight2 = new THREE.PointLight(0xffffff);
// pointLight2.castShadow = true;
// pointLight2.position.set(-20, -10, -30);

const ambientLight = new THREE.AmbientLight(0xffffff, 0.5)

const directionalLight = new THREE.DirectionalLight(0xffffff, 0.5);
directionalLight.castShadow = true;
directionalLight.shadow.mapSize.x = 2048*8;
directionalLight.shadow.mapSize.y = 2048*8;
directionalLight.shadow.camera.near = 0.5;
directionalLight.shadow.camera.far = 100;
directionalLight.shadow.bias = -0.001;
directionalLight.shadow.radius = 30;
directionalLight.position.set(50, 10, 50);

// scene.add(pointLight1);
// scene.add(pointLight2);
scene.add(ambientLight);
scene.add(directionalLight);

renderer.render(scene, camera);


let controls = new OrbitControls(camera, renderer.domElement);

//import the Computer model
gltfLoader.load("WebsiteBackground2.glb", function(gltf){
  const model = gltf.scene;
  
  //set the model childeren to cast shadows
  model.children.forEach((child) => {
    if (child.isMesh) {
      child.castShadow = true;
      child.receiveShadow = true;
    }
    console.log(child)
  })

  scene.add(model);
  model.position.set(0, 0, 0);
  globalMixer = new THREE.AnimationMixer(model);
  scrollMixer = new THREE.AnimationMixer(model);
  const clips = gltf.animations;
  clips.forEach(function(clip){
    console.log(clip)

    if(clip.name.includes("scroll") || clip.name.includes("Scroll")) {
      const scrollAction = scrollMixer.clipAction(clip);
      scrollAction.play()
    } else {
      const globalAction = globalMixer.clipAction(clip)
      globalAction.play()
    }
  });

  // const clip = THREE.AnimationClip.findByName(clips, "Bar1")
  // const action = mixer.clipAction(clip)
  // action.play();

}, undefined, function(error){});



console.log(scene);

// orbit the camera around the mouse movements
document.addEventListener('mousemove', function(e){
  let sensitivity = -0.0001;
  orbit.rotateY( e.movementX * sensitivity );
  orbit.rotateX( e.movementY * sensitivity ); 
  orbit.rotation.z = 0; //this is important to keep the camera level..
})
  
//the camera rotation pivot
let orbit = new THREE.Object3D();
orbit.rotation.order = "YXZ"; //this is important to keep level, so Z should be the last axis to rotate in order...
orbit.position.set( 0, 0, 0 );
scene.add(orbit );

//offset the camera and add it to the pivot
//you could adapt the code so that you can 'zoom' by changing the z value in camera.position in a mousewheel event..
camera.position.setZ(cameraDistance);
orbit.add( camera );

//animate the scene

// scroll animation: https://sbcode.net/threejs/animate-on-scroll/
//let scrollPercent = 0;
let scrollStart = 0;
let scrollEnd = 16;
let animDuration = 3.999;

let scrollDuration = scrollEnd - scrollStart;
let animTimeScale = scrollDuration/animDuration;

function calcScrollAnimaTimeValue() {
  //get the scroll percent each frame
  let scrollPercent = ((document.documentElement.scrollTop || document.body.scrollTop) / ((document.documentElement.scrollHeight || document.body.scrollHeight) - document.documentElement.clientHeight)) * 100;
  document.getElementById('scrollProgress').innerText = 'Scroll Progress : ' + scrollPercent.toFixed(2);
  // //set the time value
  let timeValue = ((scrollPercent-scrollStart)/animTimeScale);
  // //cap the time value between 0 and 3.9
  let cappedTimeValue = Math.min(Math.max(timeValue, 0), 3.999999);

  return cappedTimeValue;
}


const clock = new THREE.Clock();

function animate() {
    requestAnimationFrame(animate);
    if(globalMixer)
      globalMixer.update(clock.getDelta());

    if(scrollMixer)
    scrollMixer.setTime(calcScrollAnimaTimeValue());
  
    renderer.render(scene, camera);
  }
  
  animate();