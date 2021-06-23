//
// Created by Administrator on 2021/6/22.
//
#include <jni.h>
#include <string>
#import "MyRSA.h"
#import "MyBASE64.h"
#include "com_nexvoo_rsajni_RsaJni.h"

extern "C" {
JNIEXPORT jstring JNICALL Java_com_nexvoo_rsajni_RsaJni_encrypt
        (JNIEnv *env, jclass cls, jstring msg_){
    const char *msg = env->GetStringUTFChars(msg_, 0);

    std::string msgC;
    msgC.assign(msg);

    std::string rsa = MyRSA::encryptRSAbyPublickey(msgC, NULL);

    std::string base64 = MyBASE64::base64_encodestring(rsa);

    env->ReleaseStringUTFChars(msg_, msg);

    return env->NewStringUTF(base64.c_str());

}

JNIEXPORT jstring JNICALL Java_com_nexvoo_rsajni_RsaJni_decrypt
        (JNIEnv *env, jclass cls, jstring msg_){
    const char *msg = env->GetStringUTFChars(msg_, 0);

    std::string msgC;
    msgC.assign(msg);

    std::string base64=MyBASE64::base64_decodestring(msgC);
    std::string rsa=MyRSA::decryptRSAbyPrivateKey(base64);

    env->ReleaseStringUTFChars(msg_, msg);

    return env->NewStringUTF(rsa.c_str());

}
}