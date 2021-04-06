// javac ScanMem.java -h .
// java -Djava.library.path=.libs ScanMem

class ScanMem {
  static {
    System.load("/home/habs/rn/scanmem/.libs/libscanmem.so.1.0.0");
    //System.loadLibrary("scanmem");
  }
  //private static native boolean s_init();
  private static native String s_get_version();
  public static void main(String args[]) {
    try {
      //s_init();
      System.out.println(s_get_version());
    } catch(UnsatisfiedLinkError e) {
      System.out.println(e.getMessage());
      throw e;
    }
  }
}