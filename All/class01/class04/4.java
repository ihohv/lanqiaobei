// https://www.nowcoder.com/practice/36fb0fd3c656480c92b569258a1223d5

import java.util.*;
import java.io.*;

// 注意类名必须为 Main, 不要有任何 package xxx 信息
public class Main {
    public static int N = 100001;
    public static int[] arr = new int[N];
    public static int n,k;
    public static HashMap<Integer,Integer> map = new HashMap();

    static StreamTokenizer st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static void nextToken(){try {st.nextToken();} catch(Exception e){e.printStackTrace();}}
    static int nextInt(){nextToken();return (int)st.nval;}
    static String nextString(){nextToken();return st.sval;}

    public static void main(String[] args) {
        n = nextInt();
        k = nextInt();
        for(int i=0;i<n;i++)
            arr[i] = nextInt();
        System.out.println(compute());
    }

    public static int compute(){
        map.clear();
        map.put(0,-1);
        int ans = 0;
        for(int i=0,sum=0;i<n;i++){
            sum += arr[i];
            if(map.containsKey(sum-k))
                ans = Math.max(ans,i-map.get(sum-k));
            if(!map.containsKey(sum))
                map.put(sum,i);
        }
        return ans;
    }
}