import java.util.Scanner;

public class readability {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in); 
    String text = scanner.nextLine();
    int words = countWords(text);
    int sentences = countSentences(text);
    int letters = countLetters(text);
    double index = calculateIndex(letters,words, sentences);
    if(index < 1) {
      System.out.println("Before Grade 1");
    }else if(index < 16) {
      System.out.printf("Grade %.0f\n", index);
    }else {
      System.out.println("Grade 16+");
    }
    scanner.close();
  }
  public static int countWords(String text) {
    String[] words = text.split("\\s+");
    return words.length;
  }
  public static int countSentences(String text) {
    String[] sentences = text.split("[.!?]");
    return sentences.length;
  }
  public static int countLetters(String text) { 
    String onlyLetters = text.replaceAll("[^a-zA-Z]", "");
    String[] letters = onlyLetters.split("");
    return letters.length;
    }  
  public static double calculateIndex(int letters,int words, int sentences) {

    // Coleman-Liau index formula
    double L = (double) letters / words * 100.0;
    double S = (double) sentences / words * 100.0;
    double index = 0.058 * L - 0.296 * S - 15.8;
    return index;
  }
}