import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Dosya adını girin: ");
        String dosyaAdi = scanner.nextLine();
        String dosyaYolu = dosyaAdi + ".txt";
        String[] satirlar = dosyaOku(dosyaYolu); // Dosyayı okuyan fonksiyonu çağır
        if (satirlar != null) {
            List<String> kelimeler = new ArrayList<>();
            for (String satir : satirlar) {
                String[] satirKelimeleri = satir.split("\\s+|,");
                for (int i = 0; i < satirKelimeleri.length; i++) {
                    satirKelimeleri[i] = satirKelimeleri[i].replaceAll("[\\[\\]]", ""); // Köşeli parantezleri kaldır
                }
                Collections.addAll(kelimeler, satirKelimeleri); // Kelimeleri listeye ekle
            }
            for (String kelime : kelimeler) {
                System.out.println(kelime); // Kelimeleri ekrana yazdır
            }
        }
        scanner.close();
    }

    public static String[] dosyaOku(String dosyaYolu) {
        try {
            File dosya = new File(dosyaYolu); // Dosya nesnesi oluştur
            Scanner scanner = new Scanner(dosya); // Dosyayı tarayan bir Scanner oluştur
            List<String> satirListesi = new ArrayList<>(); // Satırları tutacak bir liste oluştur

            while (scanner.hasNextLine()) {
                String satir = scanner.nextLine(); // Bir sonraki satırı oku
                satirListesi.add(satir); // Satırı listeye ekle
            }
            scanner.close(); // Scanner'ı kapat
            return satirListesi.toArray(new String[0]); // Listeyi diziye dönüştür ve dizi olarak döndür
        } catch (FileNotFoundException e) {
            System.out.println(dosyaYolu + " Dosya bulunamadı"); // Dosya bulunamazsa hata mesajı yazdır
            return null;
        }
    }
}
