// 武田佑樹 286120 課題2 (2)

import java.awt.Frame;
import java.awt.Button;

public class ShortButtonApp {
    public static void main(String[] args){
	Frame myFrame = new Frame("こんにちわ");
	Button okButton = new Button("OK");
	
	myFrame.add(okButton);
	myFrame.setSize(200, 100);
	myFrame.setVisible(true);
    }
}
