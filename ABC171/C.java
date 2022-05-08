import java.util.Scanner;
import java.lang.String;
import java.lang.Math;

public class Main {

  public static String GetColumnString(int index) {

    int limitDigit = 5;
    String str = "";

    int maxDigit = GetCurDigit(index);

    double[] maxPow = GetMaxDigitArray();

    for (int i = maxDigit; i >= 0; --i) {

      double pow = 0.0;

      pow = Math.pow(26.0, i);

      // 26のi乗の商を計算
      double quotient = Math.floor(index / pow);

      if (i != 0) {
        if (-0.000001 <= Math.floor(index % pow) && Math.floor(index % pow) <= 0.000001) {
          quotient -= 1;
        } else if (quotient > 26) {
          quotient = 26;
        }
      }

      char curDigit = (char) ((int) quotient + 0x40);

      str = str + curDigit.ToString();

      // 上の桁を計算したので、下の桁へ移行
      index = index - (int) (quotient * pow);
    }

    return str;
  }

  /// <summary>
  /// 現在の桁数
  /// </summary>
  /// <param name="index"></param>
  /// <returns></returns>
  public static int GetCurDigit(int index) {
    int maxDigit = 20;

    double[] maxPow = GetMaxDigitArray();
    double[] minPow = new double[maxDigit];

    // アルファベット26進の桁の最小値 計算
    // ( 例. 3桁なら 26*26 + 26 + 1 = AAA )

    minPow[0] = 1;
    for (int i = 1; i < minPow.length; ++i) {
      minPow[i] = maxPow[i - 1] + 1;
    }

    int curDigit = 0;

    // indexが26の何乗か分の桁を持っているかを計算する
    for (int i = 0; i < maxPow.length - 1; ++i) {
      if (minPow[i] <= index && index <= maxPow[i]) {
        curDigit = i;
        break;
      }
    }

    return curDigit;
  }

  /// <summary>
  /// 最大桁の配列
  /// </summary>
  /// <returns></returns>
  private static double[] GetMaxDigitArray() {
    int maxDigit = 20;

    double[] maxPow = new double[maxDigit];

    // アルファベット26進の桁の最大値 計算 ( 例. 3桁なら 26*26*26 + 26*26 + 26 = ZZZ)
    for (int i = 0; i < maxPow.length; ++i) {
      maxPow[i] = Math.Pow(26.0, i + 1);

      for (int j = i; j > 0; --j) {
        maxPow[i] += Math.Pow(26.0, j);
      }
    }

    return maxPow;
  }

  public static void main(String[] args) {

    Scanner scanner = new Scanner(System.in);
    int num = scanner.nextInt(); // ・・・①

    String str = GetColumnString(num);
    System.out.println(str);

  }

}