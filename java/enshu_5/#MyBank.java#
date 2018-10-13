// 武田佑樹 286120 課題5 (2)

import java.util.Hashtable;

public class MyBank {
    public static void main(String[] args){
        Hashtable<String, SimpleAccount> bank = new Hashtable<String, SimpleAccount>();

        SimpleAccount ichiro = new SimpleAccount("一郎");
        bank.put("一郎", ichiro);

        SimpleAccount saburo = new SimpleAccount("三郎");
        bank.put("三郎", saburo);
        
        SimpleAccount taro = new SimpleAccount("太郎");
        bank.put("太郎", taro);

        SimpleAccount hanako = new SimpleAccount("花子");
        bank.put("花子", hanako);

        int balance;

        bank.get("三郎").deposit(1000);
        bank.get("花子").deposit(5000);
        bank.get("三郎").deposit(3000);
        bank.get("花子").deposit(2000);
        balance = bank.get("一郎").showBalance();
        System.out.println("一郎の残高: " + balance);
        balance = bank.get("三郎").showBalance();
        System.out.println("三郎の残高: " + balance);
        balance = bank.get("太郎").showBalance();
        System.out.println("太郎の残高: " + balance);
        balance = bank.get("花子").showBalance();
        System.out.println("花子の残高: " + balance);
    }
}
