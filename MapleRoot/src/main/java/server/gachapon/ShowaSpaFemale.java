package server.gachapon;

/**
 * @author Alan (SharpAceX) - gachapon source classes stub
 * @author Ronan - parsed MapleSEA loots
 * <p>
 * MapleSEA-like loots src: http://maplesecrets.blogspot.com/2011/06/gachapon-showa-towns-sauna-female-spa.html
 */

public class ShowaSpaFemale extends GachaponItems {

    @Override
    public int[] getCommonItems() {
        return new int[]{

                /* Scroll */
                2048005, 2048002, 2043202, 2044602, 2043214, 2041307, 2041035, 2044104, 2044505, 2044305, 2043304, 2041309,
                2044010, 2044803, 2044814, 2044904, 2044902, 2044901,

                /* Useable drop */
                2022016, 2000005, 2022025, 2022027,

                /* Common equipment */
                1402000, 1402013, 1002418, 1022047, 1082145, 1082147, 1082146, 1082178, 1082175,

                /* Common setup */
                3010073, 3010099,

                /* Warrior equipment */
                1422013, 1432030,

                /* Magician equipment */
                1372002, 1382003,

                /* Bowman equipment */
                1040023,

                /* Thief equipment */
                1332003, 1002209,

                /* Pirate equipment */
                1082198, 1082213, 1482007, 1492004, 1002646

        };
    }

    @Override
    public int[] getUncommonItems() {
        return new int[]{2040916, 1102042};
    }

    @Override
    public int[] getRareItems() {
        return new int[]{};
    }

}
