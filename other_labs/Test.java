package other_labs;

import java.util.Scanner;


public class Test{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Количество городов: ");
        int citiesQuantity = in.nextInt();
        float[][] citiesMap = new float [citiesQuantity][citiesQuantity];
        System.out.println("Расстояния: ");
        for (int i = 0; i < citiesQuantity; i++) {
            for (int j = 0; j < citiesQuantity; j++) {
                citiesMap[i][j] = in.nextFloat();
            }
        }
        CityMap map = new CityMap(citiesQuantity, citiesMap);
        System.out.println(map);
    }
}
