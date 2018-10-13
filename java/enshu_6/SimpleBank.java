// 武田佑樹 286120 課題6

import java.util.Hashtable;

public class SimpleBank {
    private Hashtable<String, SimpleAccount> customer;
    private SimpleAccount user;
    private boolean search;
    private int judge;
    
    public SimpleBank() {
        customer = new Hashtable<String, SimpleAccount>();
    }

    public int open(String name){
        search = customer.containsKey(name);

        if(search){
            return -7;
        } else {
            user = new SimpleAccount(name);
            customer.put(name, user);
            return 0;
        }
    }
    
    public int close(String name){
        search = customer.containsKey(name);

        if(!search){
            return -7;
        } else {
            user = customer.get(name);
            judge = user.showBalance();

            if(judge > 0){
                return -1;
            } else {
                customer.remove(name);
                return 0;
            }
        }
    }
    
    public int deposit(String name, int amount){
        search = customer.containsKey(name);
        
        if(!search){
            return -7;
        } else {
            user = customer.get(name);
            judge = user.deposit(amount);

            if(judge == -3){
                return -3;
            } else {
                return 0;
            }
        }
    }
    
    public int withdraw(String name, int amount){
        search = customer.containsKey(name);
        
        if(!search){
            return -7;
        } else {
            user = customer.get(name);
            judge = user.withdraw(amount);
            
            if(judge == -3){
                return -3;
            } else if(judge == -1){
                return -1;
            } else {
                return 0;
            }
        }
    }
        
    public int showBalance(String name){
        search = customer.containsKey(name);

        if(!search){
            return -7;
        } else {
            user = customer.get(name);
            judge = user.showBalance();
            
            return judge;
        }
    }
}
