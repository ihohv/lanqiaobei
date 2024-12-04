// https://www.lanqiao.cn/problems/3291/learning/?page=1&first_category_id=1&problem_id=3291
import java.util.Scanner;
// 1:无需package
// 2: 类名必须Main, 不可修改

public class Main {
   // 一维差分
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            int a[] = new int[n + 1];
            int b[] = new int[n + 1];// 差分数组
            int m = sc.nextInt();
            for (int i = 1; i <= n; i++) {
                a[i] = sc.nextInt();
                b[i] = a[i] - a[i - 1];
            }
            for (int i = 1; i <= m; i++) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                int z = sc.nextInt();
                b[x] += z;
                if (y < n) {
                    b[y + 1] -= z;
                }

            }
            for (int i = 1; i <= n; i++) {
                a[i] = b[i] + a[i - 1];
            }
            for (int i = 1; i <= n; i++) {
                System.out.print(a[i] + " ");
            }
            System.out.println();
        }
    }

}