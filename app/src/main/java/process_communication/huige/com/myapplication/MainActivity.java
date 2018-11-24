package process_communication.huige.com.myapplication;

import android.app.Activity;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

public class MainActivity extends Activity {
    static{
        //加载打包完毕的 so类库
        System.loadLibrary("hello");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        String s = "hello，我现在在学习jni";
        String result=sayHello(s,false);
        Log.i("TAG","result=" + result);
    }
    private native String sayHello(String message,boolean flag);
}
