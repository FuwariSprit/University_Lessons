class Book {
    private String title;
    private int price;

    public Book(String newTitle, int newPrice){
        this.title = newTitle;
        this.price = newPrice;
    }

    public void showTitle(){
        System.out.println("この本の題名は" + title + "で値段は" + price + "円です");
    }
}
