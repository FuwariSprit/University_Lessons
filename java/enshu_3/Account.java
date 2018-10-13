// 武田佑樹 286120 課題3 (1)
public class Account {
    private String name;
    private int balance;

    public Account(String myName){
        name = myName;
        balance = 0;
    }

    public void deposit(int amount){
        if(amount <= 0){
            System.out.println("不正な金額が指定されました");
        } else {
            balance += amount;
            System.out.println(name + "さんの口座へ" + amount +
                               "円預金し, 残高は" + balance + "円となりました");
        }
    }

    public void withdraw(int amount){
        if(amount > balance){
            System.out.println("残高不足です");
        } else if(amount <= 0){
            System.out.println("不正な金額が指定されました");
        } else {
            balance -= amount;
            System.out.println(name + "さんの口座から" + amount +
                               "円払い戻し, 残高は" + balance + "円となりました");
        }
    }

    public void showBalance(){
        System.out.println(name + "さんの口座の現在の残高は" + balance + "円です");
    }
}
