// 武田佑樹 286120 課題4 (1)
public class Account {
    private String name;
    private int balance;
    private String password;

    public Account(String myName){
        name = myName;
        balance = 0;
        password = "未設定";
    }

    public int setPassword(String passwd){
        if(passwd.equals(password)){
            return -6;
        } else if(passwd.length() < 8){
            return -5;
        } else {
            password = passwd;
            return 0;
        }
    }

    public int deposit(int amount){
        if(amount <= 0){
            return -3;
        } else {
            balance += amount;
            return 0;
        }
    }

    public int withdraw(int amount, String passwd){
        if(password.equals("未設定")){
            return -6;
        } else if(!passwd.equals(password)){
            return -5;
        } else if(amount <= 0){
            return -3;
        } else if(amount > balance){
            return -1;
        } else {
            balance -= amount;
            return 0;
        }
    }
    
    public int showBalance(String passwd){
        if(password.equals("未設定")){
            return -6;
        } else if(!passwd.equals(password)){
            return -5;
        } else {
            return balance;
        }
    }
    
}
