package other_labs;

public class CityMap {
    public int citiesQuant;
    public float[][] map;

    public CityMap(int cities, float[][] map){
        this.citiesQuant = cities;
        this.map = map;
    }

    public float calcPath(int[] path, int len){
        float trajectory_len = 0;
        int currentCityNumber = path[0];
        for (int i = 1; i < len; i++) {
            trajectory_len += this.map[currentCityNumber][path[i]];
            currentCityNumber = path[i];
        }
        return trajectory_len;
    }

    public String toString(){
        String representation = "";
        for (int i = 0; i < this.citiesQuant; i++) {
            for (int j = 0; j < this.citiesQuant; j++) {
                representation += this.map[i][j] + ' ';
            }
            representation += '\n';
        }
        return representation;
    }
}
