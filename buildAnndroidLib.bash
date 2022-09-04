#!/bin/bash

cd OpenRoleZoo/android/jni/
ndk-build
cd ../../../

cd SeetaAuthorize/android/jni/
ndk-build
cd ../../../

cd TenniS/android/jni/
ndk-build
cd ../../../

cd ./FaceBoxes/FaceDetector/android/jni
ndk-build
cd ../../../../

cd ./FaceTracker6/FaceTracking/android/jni
ndk-build
cd ../../../../

cd ./QualityAssessor3/QualityAssessor/android/jni
ndk-build
cd ../../../../

cd ./SeetaGenderPredictor/GenderPredictor/android/jni
ndk-build
cd ../../../../

cd ./Landmarker/Landmarker/android/jni
ndk-build
cd ../../../../

cd ./SeetaMaskDetector/MaskDetector/android/jni
ndk-build
cd ../../../../

cd ./FaceAntiSpoofingX6/FaceAntiSpoofingX/android/jni
ndk-build
cd ../../../../

cd ./SeetaAgePredictor/AgePredictor/android/jni
ndk-build
cd ../../../../

cd ./FaceRecognizer6/FaceRecognizer/android/jni
ndk-build
cd ../../../../

cd ./PoseEstimator6/PoseEstimation/android/jni
ndk-build
cd ../../../../

cd ./SeetaEyeStateDetector/EyeStateDetector/android/jni
ndk-build
cd ../../../../
