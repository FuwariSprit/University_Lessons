// 武田佑樹 286120 課題4 (2)
public class AccountTestDriver {
    public static void main(String[] args){
        Account user = new Account("武田佑樹");
        Account user2 = new Account("武田佑樹");
        Account user3 = new Account("武田佑樹");

        int resultPass, resultDepo, resultDraw, resultShow;

        // ---------- setPasswordのテスト ----------
        System.out.println("---------- setPassword ----------");
        //正常終了の確認
        System.out.println("--- 正常終了 ---");
        resultPass = user.setPassword("01234567");
        System.out.println("入力したPW: \"01234567\"");
        if(resultPass == 0){
            System.out.println("戻り値0で正常");
        } else {
            System.out.println("戻り値" + resultPass + "でエラー");
        }        
        System.out.println("----------------");

        //PWが8文字未満のエラー
        System.out.println("--- PWが8文字未満 ---");
        resultPass = user.setPassword("0123456");
        System.out.println("入力したPW: \"0123456\"");
        if(resultPass == 0){
            System.out.println("戻り値0で正常");
        } else {
            System.out.println("戻り値" + resultPass + "でエラー");
        }
        System.out.println("----------------");

        //同じPW設定のエラー
        System.out.println("--- 同じPWを設定 ---");
        System.out.println("現在のPW: \"01234567\"");
        resultPass = user.setPassword("01234567");
        System.out.println("入力したPW: \"01234567\"");
        if(resultPass == 0){
            System.out.println("戻り値0で正常");
        } else {
            System.out.println("戻り値" + resultPass + "でエラー");
        }
        System.out.println("----------------");

        // ---------- depositのテスト ----------
        System.out.println("\n---------- deposit ----------");
        //正常終了
        System.out.println("--- 正常終了 ---");
        System.out.println("残高" + user.showBalance("01234567"));
        resultDepo = user.deposit(10000);
        System.out.println("預金額: 10000");
        if(resultDepo == 0){
            System.out.println("戻り値0で正常");
            System.out.println("残高" + user.showBalance("01234567"));
        } else {
            System.out.println("戻り値" + resultDepo + "でエラー");
            System.out.println("残高" + user.showBalance("01234567"));
        }
        System.out.println("----------------");

        //0以下の額を預金のエラー
        System.out.println("--- 預金額が0以下 ---");
        System.out.println("残高" + user.showBalance("01234567"));
        resultDepo = user.deposit(-10000);
        System.out.println("預金額: -10000");
        if(resultDepo == 0){
            System.out.println("戻り値0で正常");
            System.out.println("残高" + user.showBalance("01234567"));
        } else {
            System.out.println("戻り値" + resultDepo + "でエラー");
            System.out.println("残高" + user.showBalance("01234567"));
        }
        System.out.println("----------------");

        
        // ----------- withdrawのテスト ----------
        System.out.println("\n---------- withdraw ----------");
        // 初期パスワードエラー
        System.out.println("--- 初期PWを設定 ---");
        System.out.println("新規に[user2]でインスタンス化");
        System.out.println("現在のPW: \"未設定\"");
        resultDraw = user2.withdraw(10000, "未設定");
        System.out.println("入力したPW: \"未設定\"");
        System.out.println("出金額: 10000");
        if(resultDraw == 0){
            System.out.println("戻り値0で正常");
            user2.setPassword("01234567");
            System.out.println("確認のためにPWを設定しました");
            System.out.println("残高" + user2.showBalance("01234567"));
        } else {
            System.out.println("戻り値" + resultDraw + "でエラー");
            user2.setPassword("01234567");
            System.out.println("確認のためにPWを設定しました");
            System.out.println("残高" + user2.showBalance("01234567"));
        }
        System.out.println("[user2]終了");
        System.out.println("--------------------");

        // 誤ったパスワードのエラー
        System.out.println("--- 誤ったパスワード入力 ---");
        System.out.println("残高" + user.showBalance("01234567"));
        resultDraw = user.withdraw(10000, "12345678");
        System.out.println("入力したPW: \"12345678\"");
        System.out.println("出金額: 10000");
        if(resultDraw == 0){
            System.out.println("戻り値0で正常");
            System.out.println("残高" + user.showBalance("01234567"));
        } else {
            System.out.println("戻り値" + resultDraw + "でエラー");
            System.out.println("残高" + user.showBalance("01234567"));
        }
        System.out.println("----------------------------");

        //0以下の額を引き出すエラー
        System.out.println("--- 0以下の額の引き出し ---");
        System.out.println("残高" + user.showBalance("01234567"));
        resultDraw = user.withdraw(0, "01234567");
        System.out.println("出金額: 0");
        if(resultDraw == 0){
            System.out.println("戻り値0で正常");
            System.out.println("残高" + user.showBalance("01234567"));
        } else {
            System.out.println("戻り値" + resultDraw + "でエラー");
            System.out.println("残高" + user.showBalance("01234567"));
        }
        System.out.println("---------------------------");

        // 預金残高<引き出す額のエラー
        System.out.println("--- 預金残高よりも多い引き出し ---");
        System.out.println("残高" + user.showBalance("01234567"));
        resultDraw = user.withdraw(10001, "01234567");
        System.out.println("出金額: 10001");
        if(resultDraw == 0){
            System.out.println("戻り値0で正常");
            System.out.println("残高" + user.showBalance("01234567"));
        } else {
            System.out.println("戻り値" + resultDraw + "でエラー");
            System.out.println("残高" + user.showBalance("01234567"));
        }
        System.out.println("----------------------------------");

        // 正常終了
        System.out.println("--- 正常終了 ---");
        System.out.println("残高" + user.showBalance("01234567"));
        resultDraw = user.withdraw(5000, "01234567");
        System.out.println("出金額: 5000");
        if(resultDraw == 0){
            System.out.println("戻り値0で正常");
            System.out.println("残高" + user.showBalance("01234567"));
        } else {
            System.out.println("戻り値" + resultDraw + "でエラー");
            System.out.println("残高" + user.showBalance("01234567"));
        }
        System.out.println("----------------");

        // ---------- showBalanceのテスト ----------
        System.out.println("\n---------- showBalance ----------");

        // 初期パスワードエラー
        System.out.println("--- 初期PWを入力 ---");
        System.out.println("新規に[user3]でインスタンス化しました");
        System.out.println("現在のPW: \"未設定\"");
        resultShow = user3.showBalance("未設定");
        System.out.println("入力したPW: \"未設定\"");
        if(resultShow == 0){
            System.out.println("戻り値0で正常");
        } else {
            System.out.println("戻り値" + resultShow + "でエラー");
        }
        System.out.println("[user3]終了");
        System.out.println("--------------------");

        //誤ったパスワードのエラー
        System.out.println("--- 誤ったPWを入力 ---");
        resultShow = user.showBalance("12345678");
        System.out.println("入力したPW: 12345678");
        if(resultDraw == 0){
            System.out.println("戻り値0で正常");
        } else {
            System.out.println("戻り値" + resultDraw + "でエラー");
        }
        System.out.println("----------------------");

        //正常終了
        System.out.println("--- 正常終了 ---");
        resultShow = user.showBalance("01234567");
        System.out.println("入力したPW: 01234567");
        if(resultShow >= 0){
            System.out.println("残高" + resultShow);
        } else {
            System.out.println("戻り値" + resultShow + "でエラー");
        }
        System.out.println("----------------");
    }
}
