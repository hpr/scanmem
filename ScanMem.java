// javac ScanMem.java
// sudo cp .libs/libscanmem.so.1.0.0 /usr/lib/jni

class ScanMem {
  public static void main(String args[]) {
    s_init();
    System.out.println(s_get_version());
  }
  static {
    System.loadLibrary("libscanmem.so.1.0.0");
  }
  private static native boolean s_init();
  private static native String s_get_version();
}