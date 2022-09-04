#include <seeta/JNIFaceLandmarker.h>
#include <seeta/jni_struct.hpp>

#include <seeta/FaceLandmarker.h>
#include <orz/mem/need.h>

using NativeClass = seeta::FaceLandmarker;

template<typename T>
static void delete_array(T * ptr) {
    delete [] ptr;
}

template<typename T>
static void delete_obj(T * ptr) {
    delete ptr;
}

JNIEXPORT void JNICALL Java_com_seeta_sdk_FaceLandmarker_construct__Lcom_seeta_sdk_SeetaModelSetting_2
  (JNIEnv *env, jobject self, jobject model)
  {
	jclass setting_class = env->GetObjectClass(model);
	jfieldID setting_field_id = env->GetFieldID(setting_class, "id", "I");
    jint jid = env->GetIntField(model, setting_field_id);

	jfieldID setting_field_device = env->GetFieldID(setting_class, "device", "Lcom/seeta/sdk/SeetaDevice;");
    jobject device_obj = env->GetObjectField(model, setting_field_device);
	jclass device_class = env->FindClass("com/seeta/sdk/SeetaDevice");
        
    jmethodID getVal = env->GetMethodID(device_class, "getValue", "()I");
     jint device_id = env->CallIntMethod(device_obj, getVal);

	jfieldID setting_field_model = env->GetFieldID(setting_class, "model", "[Ljava/lang/String;");
     jobjectArray model_obj = (jobjectArray)env->GetObjectField(model, setting_field_model);
     int len = env->GetArrayLength(model_obj);
       
     std::vector<std::string> modellst; 
     for(int i=0; i<len; i++) {

        jstring str = (jstring)env->GetObjectArrayElement(model_obj, i);
        auto model_path = jni_convert_string(env, str);
        modellst.push_back(model_path);
     } 

	jclass self_class = env->GetObjectClass(self);
	jfieldID self_filed_impl = env->GetFieldID(self_class, "impl", "J");

	seeta::ModelSetting::Device device = (seeta::ModelSetting::Device)device_id;//seeta::ModelSetting::AUTO;
	int id = jid; //0;
         
	seeta::ModelSetting model_setting(modellst, device, id);
	
	NativeClass *native_impl = nullptr;
	try
	{
		native_impl = new NativeClass(model_setting);
	}
	catch (const std::exception &e)
	{
		jni_throw(env, e.what());
                return;
	}
	
	jlong self_impl = reinterpret_cast<jlong>(native_impl);

	env->SetLongField(self, self_filed_impl, self_impl);  
  }
  
  
  JNIEXPORT void JNICALL Java_com_seeta_sdk_FaceLandmarker_dispose
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
  
  JNIEXPORT jint JNICALL Java_com_seeta_sdk_FaceLandmarker_number
  (JNIEnv *env, jobject self)
  {
	jclass self_class = env->GetObjectClass(self);
	jfieldID self_filed_impl = env->GetFieldID(self_class, "impl", "J");

	jlong self_impl = env->GetLongField(self, self_filed_impl);

	if (!self_impl) return 0;

	auto native_impl = reinterpret_cast<NativeClass *>(self_impl);
	
	return native_impl->number();
  }
  
JNIEXPORT void JNICALL Java_com_seeta_sdk_FaceLandmarker_mark__Lcom_seeta_sdk_SeetaImageData_2Lcom_seeta_sdk_SeetaRect_2_3Lcom_seeta_sdk_SeetaPointF_2
  (JNIEnv *env, jobject self, jobject image, jobject face, jobjectArray points)
  {
	jclass self_class = env->GetObjectClass(self);
	jfieldID self_filed_impl = env->GetFieldID(self_class, "impl", "J");

	jlong self_impl = env->GetLongField(self, self_filed_impl);

	if (!self_impl) return;

	auto native_impl = reinterpret_cast<NativeClass *>(self_impl);

	auto native_image = jni_convert_image_data(env, image);
    orz::need  n(delete_array<uint8_t>,native_image.data);

    SeetaRect facerect = jni_convert_face_info(env, face);

    int len = env->GetArrayLength(points);
    std::vector<SeetaPointF> native_points;
    native_points.resize(len);
	
	native_impl->mark(native_image, facerect, native_points.data());
    
	for(int i=0; i<len; i++) 
	{
        jobject obj = jni_convert(env, native_points[i]);
        env->SetObjectArrayElement(points, i, obj);
    }

  }
  
  JNIEXPORT void JNICALL Java_com_seeta_sdk_FaceLandmarker_mark__Lcom_seeta_sdk_SeetaImageData_2Lcom_seeta_sdk_SeetaRect_2_3Lcom_seeta_sdk_SeetaPointF_2_3I
  (JNIEnv *env, jobject self, jobject image, jobject face, jobjectArray points, jintArray mask)
  {
	jclass self_class = env->GetObjectClass(self);
	jfieldID self_filed_impl = env->GetFieldID(self_class, "impl", "J");

	jlong self_impl = env->GetLongField(self, self_filed_impl);

	if (!self_impl) return;

	auto native_impl = reinterpret_cast<NativeClass *>(self_impl);

	auto native_image = jni_convert_image_data(env, image);
    orz::need  n(delete_array<uint8_t>,native_image.data);

    SeetaRect facerect = jni_convert_face_info(env, face);

    int len = env->GetArrayLength(points);
    std::vector<SeetaPointF> native_points;
    native_points.resize(len);
	
	std::vector<int> native_mask;
	native_mask.resize(len);
	
	native_impl->mark(native_image, facerect, native_points.data(), native_mask.data());
    
	for(int i=0; i<len; i++) 
	{
        jobject obj = jni_convert(env, native_points[i]);
        env->SetObjectArrayElement(points, i, obj);
		
    }
	env->SetIntArrayRegion(mask, 0, len, native_mask.data());
  }
