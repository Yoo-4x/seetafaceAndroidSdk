#include <seeta/JNIQualityOfBrightness.h>
#include <seeta/QualityOfBrightness.h>

#include <seeta/jni_struct.hpp>

#include <orz/mem/need.h>


#include <memory>

using NativeClass = seeta::QualityOfBrightness;

template<typename T>
static void delete_array(T * ptr) {
    delete [] ptr;
}

template<typename T>
static void delete_obj(T * ptr) {
    delete ptr;
}

JNIEXPORT void JNICALL Java_com_seeta_sdk_QualityOfBrightness_construct__
  (JNIEnv *env, jobject self)
  {
	jclass self_class = env->GetObjectClass(self);
	jfieldID self_filed_impl = env->GetFieldID(self_class, "impl", "J");
	
	NativeClass *native_impl = nullptr;
	try
	{
		native_impl = new NativeClass();
	}
	catch (const std::exception &e)
	{
		jni_throw(env, e.what());
        return;
	}
	
	jlong self_impl = reinterpret_cast<jlong>(native_impl);

	env->SetLongField(self, self_filed_impl, self_impl); 
  }
  
  JNIEXPORT void JNICALL Java_com_seeta_sdk_QualityOfBrightness_construct__FFFF
  (JNIEnv *env, jobject self, jfloat v0, jfloat v1, jfloat v2, jfloat v3)
  {
	jclass self_class = env->GetObjectClass(self);
	jfieldID self_filed_impl = env->GetFieldID(self_class, "impl", "J");
	
	NativeClass *native_impl = nullptr;
	try
	{
		native_impl = new NativeClass(v0, v1, v2, v3);
	}
	catch (const std::exception &e)
	{
		jni_throw(env, e.what());
        return;
	}
	
	jlong self_impl = reinterpret_cast<jlong>(native_impl);

	env->SetLongField(self, self_filed_impl, self_impl);  
  }
  
  JNIEXPORT void JNICALL Java_com_seeta_sdk_QualityOfBrightness_dispose
  (JNIEnv *env, jobject self)
  {
	jclass self_class = env->GetObjectClass(self);
	jfieldID self_filed_impl = env->GetFieldID(self_class, "impl", "J");

	jlong self_impl = env->GetLongField(self, self_filed_impl);

	if (!self_impl) return;

	auto native_impl = reinterpret_cast<NativeClass *>(self_impl);
	delete native_impl;

	env->SetLongField(self, self_filed_impl, 0); 
  }
  
  JNIEXPORT jint JNICALL Java_com_seeta_sdk_QualityOfBrightness_checkCore
  (JNIEnv *env, jobject self, jobject image, jobject info, jobjectArray landmarks, jfloatArray score)
  {
	jclass self_class = env->GetObjectClass(self);
	jfieldID self_filed_impl = env->GetFieldID(self_class, "impl", "J");

	jlong self_impl = env->GetLongField(self, self_filed_impl);

	if (!self_impl) return -1;

	auto native_impl = reinterpret_cast<NativeClass *>(self_impl);

	auto native_image = jni_convert_image_data(env, image);
	auto native_info = jni_convert_face_info(env, info);
	std::vector<SeetaPointF> native_points = jni_convert_landmarks(env, landmarks);
	
	seeta::QualityResult result = native_impl->check(native_image, native_info, 
	native_points.data(), native_points.size());
	
	env->SetFloatArrayRegion(score, 0, 1, &result.score);
	
	delete[] native_image.data;
	
	return (jint)result.level;
  }