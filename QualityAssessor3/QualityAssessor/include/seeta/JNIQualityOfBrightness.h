/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_seeta_sdk_QualityOfBrightness */

#ifndef _Included_com_seeta_sdk_QualityOfBrightness
#define _Included_com_seeta_sdk_QualityOfBrightness
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_seeta_sdk_QualityOfBrightness
 * Method:    construct
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_seeta_sdk_QualityOfBrightness_construct__
  (JNIEnv *, jobject);

/*
 * Class:     com_seeta_sdk_QualityOfBrightness
 * Method:    construct
 * Signature: (FFFF)V
 */
JNIEXPORT void JNICALL Java_com_seeta_sdk_QualityOfBrightness_construct__FFFF
  (JNIEnv *, jobject, jfloat, jfloat, jfloat, jfloat);

/*
 * Class:     com_seeta_sdk_QualityOfBrightness
 * Method:    dispose
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_seeta_sdk_QualityOfBrightness_dispose
  (JNIEnv *, jobject);

/*
 * Class:     com_seeta_sdk_QualityOfBrightness
 * Method:    checkCore
 * Signature: (Lcom/seeta/sdk/SeetaImageData;Lcom/seeta/sdk/SeetaRect;[Lcom/seeta/sdk/SeetaPointF;[F)I
 */
JNIEXPORT jint JNICALL Java_com_seeta_sdk_QualityOfBrightness_checkCore
  (JNIEnv *, jobject, jobject, jobject, jobjectArray, jfloatArray);

#ifdef __cplusplus
}
#endif
#endif