import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;

public class Parser {

    public static boolean hatavardir=false;

    public static List<String> dosyadanSatirlariOku(String dosyaAdi) {
        List<String> satirlar = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(dosyaAdi))) {
            String satir;
            while ((satir = br.readLine()) != null) {
                satirlar.add(satir);
            }
        } catch (IOException e) {
            System.err.println("Dosya okuma hatasi: " + e.getMessage());
        }

        return satirlar;
    }

    public static boolean sabitmi(String input) {
        if (input.startsWith("[") && input.endsWith("]")) {
            try {
                String numberStr = input.substring(1, input.length() - 1);
                int number = Integer.parseInt(numberStr);
                return true;
            } catch (NumberFormatException e) {
                return false;
            }
        }
        return false;
    }

    public static boolean sayimi(String input) {
        if (input == null || input.isEmpty()) {
            return false;
        }
        for (char c : input.toCharArray()) {
            if (!Character.isDigit(c)) {
                return false;
            }
        }
        return true;
    }

    public static boolean degiskenmi(String degisken){
        if (Objects.equals(degisken, "AX") || Objects.equals(degisken, "BX") || Objects.equals(degisken, "CX") || Objects.equals(degisken, "DX")){
            return true;
        }
        return false;
    }

    public static boolean etiketmi(String satir){

        String[] parcalar = parcala(satir);

        if (parcalar.length != 2) {
            return true;
        }else{
            return false;
        }
    }
    public static boolean degermi(String satir){
        String[] parcalar = parcala(satir);

        if (parcalar.length != 2) {
            return true;
        }else{
            if ((sabitmi(parcalar[1])||sayimi(parcalar[1])||degiskenmi(parcalar[1]))){
                return false;
            }else{
                return true;
            }
        }
    }

    public static String[] parcala(String satir){
        return satir.split("[,\\s]+");
    }

    public static boolean ciftkontrol(String satir) {
        String[] parcalar = parcala(satir);

        if (parcalar.length != 3) {
            return true;
        }

        if ((sabitmi(parcalar[1]) || degiskenmi(parcalar[1]) || sayimi(parcalar[1]))
                && (sabitmi(parcalar[2]) || degiskenmi(parcalar[2]) || sayimi(parcalar[2]))) {
            return false;
        } else {
            return true;
        }
    }

    public static boolean kontrolet(String satir) {

        if (satir.startsWith("TOP ") || satir.startsWith("CRP ") || satir.startsWith("BOL ") || satir.startsWith("CIK ")) {
            return ciftkontrol(satir);
        }
        else if (satir.startsWith("D ") || satir.startsWith("DB ") ||
                satir.startsWith("DK ") || satir.startsWith("DKE ") || satir.startsWith("DBE ") ||
                satir.startsWith("DED ") || satir.startsWith("DE ") ) {
            return etiketmi(satir);
        }
        else if (satir.startsWith("HRK ") ||
                satir.startsWith("VE ") || satir.startsWith("VEY ") ) {
            return ciftkontrol(satir);
        }
        else if (satir.startsWith("DEG ") ||
                satir.startsWith("OKU ") || satir.startsWith("YAZ ")) {
            return degermi(satir);
        }
        else {
            return true;
        }
    }
    public static void hataver(int satirno,String satir){
        boolean var=kontrolet(satir);
        if (var) {
            hatavardir=true;
            System.out.println(satirno+".satirda hata var");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Lütfen dosya adını girin: ");
        String dosyaAdi = scanner.nextLine();
        int i=1;

        List<String> satirlar = dosyadanSatirlariOku(dosyaAdi);

        for (String satir:satirlar
             ) {
            hataver(i,satir);
            i++;
        }
        if (hatavardir!=true){
            System.out.println("Hata yok");
        }
        scanner.close();
    }
}
