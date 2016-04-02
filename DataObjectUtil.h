/* 
 * File:   DataObjectUtil.h
 * Author: Rickard
 *
 * Created on den 22 oktober 2015, 19:52
 */
#include <osvr/Util/ClientReportTypesC.h>

#ifndef DATAOBJECTUTIL_H
#define	DATAOBJECTUTIL_H
#define JNI_FALSE 0
#define JNI_TRUE 1
#define ZERO 0
#define VEC3_LEN 3
#define QUAT_LEN 4
#define VIEWMAT_LEN 16

inline jfieldID getDoubleArrayField(JNIEnv *env, jobject obj)
{
    jclass c = env->GetObjectClass(obj);
    return env->GetFieldID(c, "data", "[D");
}

inline void setVec3Data(JNIEnv *env, jobject obj, OSVR_PositionState vec)
{
    jdoubleArray jdata = (jdoubleArray)env->GetObjectField(obj, getDoubleArrayField(env, obj));
//    if(NULL == jdata ||  0 == env->GetArrayLength(jdata)){
//        jdata = env->NewDoubleArray(VEC3_LEN);
//    }
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

inline void setButtonData(JNIEnv *env, jobject obj, OSVR_ButtonState button){
    jclass c = env->GetObjectClass(obj);
    jfieldID fieldID = env->GetFieldID(c, "button", "Losvr/util/OSVR_Button;");
    jobject jdata = (jobject)env->GetObjectField(obj, getDoubleArrayField(env, obj));
    env->SetBooleanField( jdata, fieldID, button == OSVR_TRUE);
}

inline void setViewMatrixData(JNIEnv *env, jobject obj, float matrix[], jfloatArray jmatrix){
    
    env->SetFloatArrayRegion( jmatrix, ZERO, VIEWMAT_LEN, matrix);
}
#endif	/* DATAOBJECTUTIL_H */

