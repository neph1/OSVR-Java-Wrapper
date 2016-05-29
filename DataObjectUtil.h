/* 
 * File:   DataObjectUtil.h
 * Author: Rickard
 *
 * Created on den 22 oktober 2015, 19:52
 */
#include <osvr/Util/ClientReportTypesC.h>
#include <osvr/Util/RenderingTypesC.h>
#include <osvr/Util/RadialDistortionParametersC.h>
#include <string>
#include <iostream>
#ifndef DATAOBJECTUTIL_H
#define	DATAOBJECTUTIL_H
#define JNI_FALSE 0
#define JNI_TRUE 1
#define ZERO 0
#define VEC2_LEN 2
#define VEC3_LEN 3
#define QUAT_LEN 4
#define VIEWMAT_LEN 16
#define VIEWPORT_LENGTH 4

inline jfieldID getDoubleArrayField(JNIEnv *env, jobject obj)
{
    jclass c = env->GetObjectClass(obj);
    return env->GetFieldID(c, "data", "[D");
}


inline void setVec2Data(JNIEnv *env, jobject obj, OSVR_Vec2 vec)
{
    jdoubleArray jdata = (jdoubleArray)env->GetObjectField(obj, getDoubleArrayField(env, obj));
    env->SetDoubleArrayRegion( jdata, ZERO, VEC2_LEN, vec.data);
}

inline void setVec3Data(JNIEnv *env, jobject obj, OSVR_Vec3 vec)
{
    jdoubleArray jdata = (jdoubleArray)env->GetObjectField(obj, getDoubleArrayField(env, obj));
    env->SetDoubleArrayRegion( jdata, ZERO, VEC3_LEN, vec.data);
}

inline void setQuatData(JNIEnv *env, jobject obj, OSVR_OrientationState quat)
{
    jdoubleArray jdata = (jdoubleArray)env->GetObjectField(obj, getDoubleArrayField(env, obj));
    env->SetDoubleArrayRegion( jdata, ZERO, QUAT_LEN, quat.data);
}

inline void setPose3Data(JNIEnv *env, jobject obj, OSVR_PoseState pose)
{
    jclass c = env->GetObjectClass(obj);
    // Position
    jfieldID fieldID = env->GetFieldID(c, "translation", "Losvr/util/OSVR_Vec3;");
    jobject position = (jobject)env->GetObjectField(obj, fieldID);
    setVec3Data(env, position, pose.translation);
    // Orientation
    fieldID = env->GetFieldID(c, "rotation", "Losvr/util/OSVR_Quaternion;");
    jobject rotation = (jobject)env->GetObjectField(obj, fieldID);
    setQuatData(env, rotation, pose.rotation);
}

inline void setDistortionParameters(JNIEnv *env, jobject obj, OSVR_RadialDistortionParameters params){
    jclass c = env->GetObjectClass(obj);
    jfieldID fieldID = env->GetFieldID(c, "k1", "Losvr/util/OSVR_Vec3;");
    jobject position = (jobject)env->GetObjectField(obj, fieldID);
    setVec3Data(env, position, params.k1);
    fieldID = env->GetFieldID(c, "centerOfProjection", "Losvr/util/OSVR_Vec2;");
    position = (jobject)env->GetObjectField(obj, fieldID);
    setVec2Data(env, position, params.centerOfProjection);
}

inline void setButtonData(JNIEnv *env, jobject obj, OSVR_ButtonState button){
    jclass c = env->GetObjectClass(obj);
    jfieldID fieldID = env->GetFieldID(c, "button", "Losvr/util/OSVR_Button;");
    jobject jdata = (jobject)env->GetObjectField(obj, getDoubleArrayField(env, obj));
    env->SetBooleanField( jdata, fieldID, button == OSVR_TRUE);
}

inline void setMatrixData(JNIEnv *env, jobject obj, float matrix[], jfloatArray jmatrix){
    int i;
    jfloat arr[VIEWMAT_LEN] = { };
    for (i = 0; i < VIEWMAT_LEN; i++) {
        arr[i] = matrix[i]; 
    }
    env->SetFloatArrayRegion( jmatrix, ZERO, VIEWMAT_LEN, matrix);
}
#endif	/* DATAOBJECTUTIL_H */

inline void setViewportData(JNIEnv *env, jobject obj, OSVR_ViewportDimension matrix[], jintArray jmatrix)
{
    int i;
    jint arr[VIEWPORT_LENGTH] = { };
    for (i = 0; i < VIEWPORT_LENGTH; i++) {
        arr[i] = matrix[i]; 
    }
    
    env->SetIntArrayRegion( jmatrix, ZERO, VIEWPORT_LENGTH, arr);
}

inline void releaseFloatArray(JNIEnv *env, jobject obj, jfloatArray jArray){
    jfloat* elem = env->GetFloatArrayElements(jArray, 0);
    env->ReleaseFloatArrayElements(jArray, (jfloat*)elem, 0);
}

inline void releaseDoubleArray(JNIEnv *env, jobject obj, jdoubleArray jArray){
    jdouble* elem = env->GetDoubleArrayElements(jArray, 0);
    env->ReleaseDoubleArrayElements(jArray, (jdouble*)elem, 0);
}

inline void releaseIntArray(JNIEnv *env, jobject obj, jintArray jArray){
    jint* elem = env->GetIntArrayElements(jArray, 0);
    env->ReleaseIntArrayElements(jArray, (jint*)elem, 0);
}

