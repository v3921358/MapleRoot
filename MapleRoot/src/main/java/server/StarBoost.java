package server;

public class StarBoost {
    private int watk;
    private int matk;
    private int str;
    private int dex;
    private int luk;
    private int intStat;

    public StarBoost(int watk, int matk, int str, int dex, int luk, int intStat) {
        this.watk = watk;
        this.matk = matk;
        this.str = str;
        this.dex = dex;
        this.luk = luk;
        this.intStat = intStat;
    }

    // Getters
    public int getWatk() { return watk; }
    public int getMatk() { return matk; }
    public int getStr() { return str; }
    public int getDex() { return dex; }
    public int getLuk() { return luk; }
    public int getInt() { return intStat; }

    // Setters
    public void setWatk(int watk) { this.watk = watk; }
    public void setMatk(int matk) { this.matk = matk; }
    public void setStr(int str) { this.str = str; }
    public void setDex(int dex) { this.dex = dex; }
    public void setLuk(int luk) { this.luk = luk; }
    public void setInt(int intStat) { this.intStat = intStat; }

    @Override
    public String toString() {
        return "StatBoost{" +
                "watk=" + watk +
                ", matk=" + matk +
                ", str=" + str +
                ", dex=" + dex +
                ", luk=" + luk +
                ", intStat=" + intStat +
                '}';
    }
}
