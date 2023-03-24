import './style.css';

import * as THREE from 'three';
import { SVGLoader } from 'three/addons/loaders/SVGLoader.js';

import { FileAttachments } from '@observablehq/stdlib/src/fileAttachment.js'

import {OrbitControls} from "https://cdn.jsdelivr.net/npm/three@0.127.0/examples/jsm/controls/OrbitControls.js";

//Initialize the scene
let cameraPos = {x: 500, y: 750, z: 2000}

const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(75, window.innerWidth/window.innerHeight, 0.1, 10000);   // Arguments: FoV, Aspect Ratio, View Frostrum near, View Frostrum far (View Frostrum is basically how close and far away can an object be before they aren't visible)
const renderer = new THREE.WebGL1Renderer({
  canvas: document.querySelector('#bg'),
});

renderer.setPixelRatio(window.devicePixelRatio);
renderer.setSize(window.innerWidth, window.innerHeight);
renderer.setClearColor(0xFBFFF3, 1);

camera.position.set(cameraPos.x, cameraPos.y, cameraPos.z);

// Scene Lighting
const pointLight1 = new THREE.PointLight(0xffffff)
pointLight1.position.set(20, 10, 30)

const pointLight2 = new THREE.PointLight(0xffffff)
pointLight2.position.set(-20, -10, -30)

const ambientLight = new THREE.AmbientLight(0xffffff, 0.2)

scene.add(pointLight1);
scene.add(pointLight2);
scene.add(ambientLight);

renderer.render(scene, camera);

//camera controls
let controls = new OrbitControls(camera, renderer.domElement);

//load in the svg
const svgLoader = new SVGLoader();

// modify the loader code (from: https://threejs.org/docs/#examples/en/loaders/SVGLoader) 
// to load in multiple SVG files and add them to an array/dictionary

let layers = {};    //Store all layers in a dictionary, that way I can identify each layer by it's position, which is what each layer file is called

const loader = new SVGLoader();

async function SVG(url){

    let svg = await FileAttachment(url).text();
    const data = loader.parse( svg );
  
    const group = new THREE.Group();
    
    const paths = data.paths;
    
    const extrudeSettings = {
        steps: 1,
        depth: depth,
        bevelEnabled: false,
        bevelThickness: 1,
        bevelSize: 1,
        bevelOffset: 0,
        bevelSegments: 1
    };
  
    group.scale.multiplyScalar( 0.25 );
    group.position.x = - ( svgWidth / 2 ) * 0.25;
    group.position.y = ( svgHeight / 2 ) * 0.25;
    group.scale.y *= - 1;
    
    for ( let i = 0; i < paths.length; i ++ ) {
  
        const path = paths[ i ];
  
        if ( path.userData.style.fill != 'none' ) {
      
            const material = new THREE.MeshPhongMaterial( {
                color: path.userData.style.fill,
                side: THREE.DoubleSide
            } );
  
            const shapes = path.toShapes( true );
  
            for ( let j = 0; j < shapes.length; j ++ ) {
          
                let zValue = 0;

                const shape = shapes[ j ];

                const geometry = new THREE.ExtrudeGeometry( shape, extrudeSettings );

                const mesh = new THREE.Mesh( geometry, material );

                const pathNode = path.userData.node;
                const pathParent = pathNode.parentElement;

                zValue = +pathParent.id;

                mesh.position.z = zValue * depth * 1.5; 
                group.add( mesh );
  
            }
        
        }
      
    }
    return group;
}

layers["test"] = SVG('SVGs/Left_1.svg')

console.log(layers);
console.log(layers["test"]);

renderer.render(scene, camera);

function animate() {
    requestAnimationFrame(animate);
    renderer.render(scene, camera);
}

animate();