import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Dosya adini girin: ");
        String dosyaAdi = scanner.nextLine();
        String dosyaYolu = dosyaAdi + ".txt";

        try {
            File dosya = new File(dosyaYolu);
            Scanner dosyaOkuyucu = new Scanner(dosya);

            List<String> kelimeler = new ArrayList<>();

            while (dosyaOkuyucu.hasNextLine()) {
                String satir = dosyaOkuyucu.nextLine();
                String[] satirKelimeleri = satir.split("\\s+|,");

                for (String kelime : satirKelimeleri) {
                    kelimeler.add(kelime.replaceAll("[\\[\\]]", ""));
                }
            }
            String[] CS = kelimeler.toArray(new String[0]);
            for (String kelime : CS) {
                System.out.println(kelime);
            }

            dosyaOkuyucu.close();
        } catch (FileNotFoundException e) {
            System.out.println("Dosya bulunamadı veya okunamadı: " + e.getMessage());
        }

        scanner.close();
    }
}