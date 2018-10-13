public class BankTestDriver {
    public static void main(String[] args){
        int judge;
        SimpleBank test = new SimpleBank();

        judge = test.open("tashiro");
        print(judge);
        
        judge = test.deposit("tashiro", 30000);
        print(judge);
        
        judge = test.withdraw("tashiro", 30000);
        print(judge);

        judge = test.showBalance("tashiro");
        print(judge);

        judge = test.close("tashiro");
        print(judge);

        judge = test.close("tashiro");
        print(judge);
        
    }

    public static void print(int judge){
        System.out.println(judge);
    }
}
