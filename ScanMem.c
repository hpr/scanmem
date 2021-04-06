#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <jni.h>

#include "scanmem.h"

#include "ScanMem.h"

// ./configure CFLAGS="-fPIC -I/usr/lib/jvm/java-11-openjdk-amd64/include -I/usr/lib/jvm/java-11-openjdk-amd64/include/linux"
// make

JNIEXPORT jstring JNICALL Java_ScanMem_s_1get_1version(JNIEnv *env, jclass obj) {
  const char *str = sm_get_version();
  return (*env)->NewStringUTF(env, str);
};

/*
static const char *JNIT_CLASS = "ScanMem";

static jboolean s_init(JNIEnv *env, jobject obj) {
	(void)env;
	(void)obj;

  return sm_init();
}

static void s_set_backend(JNIEnv *env, jobject obj) {
  (void)env;
  (void)obj;

  sm_set_backend();
}

static void s_backend_exec_cmd(JNIEnv *env, jobject obj, jstring cmd) {
  (void)obj;

  const char *str = (*env)->GetStringUTFChars(env, cmd, 0);

  sm_backend_exec_cmd(str);
}

static jstring s_get_version(JNIEnv *env, jobject obj) {
  (void)obj;

  return (*env)->NewStringUTF(env, sm_get_version());
}

static void s_cleanup(JNIEnv *env, jobject obj) {
  (void)env;
  (void)obj;

  sm_cleanup();
}

static JNINativeMethod funcs[] = {
	{ "s_init", "()Z", (void *)&s_init },
  { "s_set_backend", "()V", (void *)&s_set_backend },
	{ "s_backend_exec_cmd", "(Ljava/lang/String;)V", (void *)&s_backend_exec_cmd },
	{ "s_get_version", "()Ljava/lang/String;", (void *)&s_get_version },
	{ "s_cleanup", "()V", (void *)&s_cleanup },
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved)
{
	JNIEnv *env;
	jclass  cls;
	jint    res;

	(void)reserved;

	if ((*vm)->GetEnv(vm, (void **)&env, JNI_VERSION_1_6) != JNI_OK)
		return -1;

	cls = (*env)->FindClass(env, JNIT_CLASS);
	if (cls == NULL)
		return -1;

	res = (*env)->RegisterNatives(env, cls, funcs, sizeof(funcs)/sizeof(*funcs));
	if (res != 0)
		return -1;

	return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved)
{
	JNIEnv *env;
	jclass  cls;

	(void)reserved;

	if ((*vm)->GetEnv(vm, (void **)&env, JNI_VERSION_1_6) != JNI_OK)
		return;

	cls = (*env)->FindClass(env, JNIT_CLASS);
	if (cls == NULL)
		return;

	(*env)->UnregisterNatives(env, cls);
}
*/