// 武田佑樹 286120 課題2 (1)

public class OneButtonApp {
    public static void main(String[] args){
	java.awt.Frame myFrame = new java.awt.Frame("こんにちわ");
	java.awt.Button okButton = new java.awt.Button("OK");
	
	myFrame.add(okButton);
	myFrame.setSize(200, 100);
	myFrame.setVisible(true);
    }
}
