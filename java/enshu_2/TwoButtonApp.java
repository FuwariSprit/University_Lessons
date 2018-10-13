// 武田佑樹 286120 課題2 (3)

import java.awt.Frame;
import java.awt.Button;
import java.awt.BorderLayout;
import java.awt.Panel;

public class TwoButtonApp {
    public static void main(String[] args){
	Frame myFrame = new Frame("TwoButtonApp");
	Panel myPanel = new Panel();
	//Panel cancelPanel = new Panel();
	Button okButton = new Button("OK");
	Button cancelButton = new Button("CANCEL");
	
	myPanel.add(okButton);
	myPanel.add(cancelButton);
	//cancelPanel.add(cancelButton);
	myFrame.add(myPanel);
	//myFrame.add(cancelPanel);
	myFrame.setSize(200, 100);
	myFrame.setVisible(true);
    }
}
