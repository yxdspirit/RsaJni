package com.nexvoo.rsajni;

public class RsaJni {
    static {
        System.loadLibrary("rsajni");
    }
    public static native String encrypt(String origin);
    public static native String decrypt(String origin);
}
