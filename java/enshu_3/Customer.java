// 武田佑樹 286120 課題3 (2)
public class Customer {
    public static void main(String[] args){
        Account user = new Account("武田佑樹");

        user.deposit(10000);
        user.showBalance();
        user.withdraw(50000);
        user.showBalance();
        user.deposit(-1000);
        user.showBalance();
        user.withdraw(-5000);
        user.showBalance();
    }
}
