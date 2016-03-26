import java.util.Scanner;
class program {

  public static void main(String[] args) {
    Scanner leer = new Scanner(System.in);
    char palabras[];
    int cont;
    boolean cond;
    while(leer.hasNext()){
      cont = 0;
      cond = false;
      palabras = leer.nextLine().toCharArray();
      for(char letra : palabras) {
        if(Character.isLetter(letra)) {
          if(!cond) {
            cont++;
            cond = true;
          }
        } else {
          cond = false;
        }
      }
      System.out.println(cont);
    }
  }
}
