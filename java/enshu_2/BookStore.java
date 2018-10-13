// 武田佑樹 286120 課題2 (5)
public class BookStore {
    public static void main(String[] args){
        Book easyJava = new Book("やさしいJava活用編", 2580);
        Book harem = new Book("終末のハーレム", 626);
        Book pptp = new Book("ポプテピピック", 797);

        easyJava.showTitle();
        harem.showTitle();
        pptp.showTitle();
    }
}
