import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;

public class execution1 {

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

    public static boolean dallanmi(String satir){

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

    public static boolean etiketmi(String satir){
        String[] parcalar = parcala(satir);

        if (parcalar[0].endsWith(":")){
            return kontrolet(parcalar[1]+" "+parcalar[2]+","+parcalar[3]);
        }else{
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
            return dallanmi(satir);
        }
        else if (satir.startsWith("HRK ") ||
                satir.startsWith("VE ") || satir.startsWith("VEY ") ) {
            return ciftkontrol(satir);
        }
        else if (satir.startsWith("DEG ") ||
                satir.startsWith("OKU ") || satir.startsWith("YAZ ")) {
            return degermi(satir);
        }else if(satir.startsWith("ETIKET")){
            return etiketmi(satir);
        }
        else {
            return true;
        }
    }
    public static void hatabul(int satirno,String satir){
        if (kontrolet(satir)) {
            hatavardir=true;
            System.out.println(satirno+".satirda hata var");
        }
    }


    public static void execution(List<String> satirlar){

        Scanner scanner=new Scanner(System.in);
        boolean atlansinmi=false;
        String atlanacaketiket="";
        int AX=0,BX=0,CX=0,DX=0;
        boolean signflag=false;
        boolean zeroflag=false;

        for (String satir : satirlar){

            if (atlansinmi==true){
                if(satir.startsWith("ETIKET")){
                    if (satir.startsWith(atlanacaketiket+":")){
                        String yeni=satir.substring(satir.indexOf(":") + 2).trim();
                        satir=yeni;
                        atlansinmi=false;
                        if (satir.startsWith("TOP ") ) {
                            //Toplama
                            String[] toplama = parcala(satir);
                            if(toplama[1].equals("AX")){
                                if(toplama[2].equals("AX") ){
                                    AX=AX+AX;
                                } else if(toplama[2].equals("BX") ){
                                    AX=AX+BX;
                                } else if (toplama[2].equals("CX") ){
                                    AX=AX+CX;
                                } else if (toplama[2].equals("DX") ){
                                    AX=AX+DX;
                                }else{
                                    AX=AX+Integer.parseInt(toplama[2]);
                                }
                            }
                            else if(toplama[1].equals("BX")){
                                if(toplama[2].equals("AX") ){
                                    BX=BX+AX;
                                }else if(toplama[2].equals("BX") ){
                                    BX=BX+BX;
                                } else if (toplama[2].equals("CX") ){
                                    BX=BX+CX;
                                } else if (toplama[2].equals("DX") ){
                                    BX=BX+DX;
                                }else{
                                    BX=BX+Integer.parseInt(toplama[2]);
                                }
                            }
                            else if(toplama[1].equals("CX")){
                                if(toplama[2].equals("AX") ){
                                    CX=CX+AX;
                                } else if (toplama[2].equals("BX") ){
                                    CX=CX+BX;
                                }else if(toplama[2].equals("CX") ){
                                    CX=CX+CX;
                                } else if (toplama[2].equals("DX") ){
                                    CX=CX+DX;
                                }else{
                                    CX=CX+Integer.parseInt(toplama[2]);
                                }
                            }
                            else if(toplama[1].equals("DX")){
                                if(toplama[2].equals("AX") ){
                                    DX=DX+AX;
                                } else if (toplama[2].equals("BX") ){
                                    DX=DX+BX;
                                } else if (toplama[2].equals("CX") ){
                                    DX=DX+CX;
                                }else if (toplama[2].equals("DX") ){
                                    DX=DX+DX;
                                }else{
                                    DX=DX+Integer.parseInt(toplama[2]);
                                }
                            }
                        }
                        else if (satir.startsWith("CIK ") ) {
                            //Çıkartma
                            String[] cikartma = parcala(satir);
                            if(cikartma[1].equals("AX")){
                                if(cikartma[2].equals("AX") ){
                                    AX=AX-AX;
                                    if(AX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (AX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                } else if(cikartma[2].equals("BX") ){
                                    AX=AX-BX;
                                    if(AX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (AX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                } else if (cikartma[2].equals("CX") ){
                                    AX=AX-CX;
                                    if(AX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (AX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                } else if (cikartma[2].equals("DX") ){
                                    AX=AX-DX;
                                    if(AX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (AX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                }else{
                                    AX=AX-Integer.parseInt(cikartma[2]);
                                    if(AX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (AX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                }
                            }
                            else if(cikartma[1].equals("BX")){
                                if(cikartma[2].equals("AX") ){
                                    BX=BX-AX;
                                    if(BX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (BX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                }else if(cikartma[2].equals("BX") ){
                                    BX=BX-BX;
                                    if(BX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (BX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                } else if (cikartma[2].equals("CX") ){
                                    BX=BX-CX;
                                    if(BX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (BX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                } else if (cikartma[2].equals("DX") ){
                                    BX=BX-DX;
                                    if(BX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (BX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                }else{
                                    BX=BX-Integer.parseInt(cikartma[2]);
                                    if(BX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (BX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                }
                            }
                            else if(cikartma[1].equals("CX")){
                                if(cikartma[2].equals("AX") ){
                                    CX=CX-AX;
                                    if(CX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (CX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                } else if (cikartma[2].equals("BX") ){
                                    CX=CX-BX;
                                    if(CX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (CX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                }else if(cikartma[2].equals("CX") ){
                                    CX=CX-CX;
                                    if(CX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (CX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                } else if (cikartma[2].equals("DX") ){
                                    CX=CX-DX;
                                    if(CX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (CX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                }else{
                                    CX=CX-Integer.parseInt(cikartma[2]);
                                    if(CX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (CX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                }
                            }
                            else if(cikartma[1].equals("DX")){
                                if(cikartma[2].equals("AX") ){
                                    DX=DX-AX;
                                    if(DX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (DX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                } else if (cikartma[2].equals("BX") ){
                                    DX=DX-BX;
                                    if(DX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (DX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                } else if (cikartma[2].equals("CX") ){
                                    DX=DX-CX;
                                    if(DX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (DX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                }else if (cikartma[2].equals("DX") ){
                                    DX=DX-DX;
                                    if(DX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (DX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                }else{
                                    DX=DX-Integer.parseInt(cikartma[2]);
                                    if(DX<0){
                                        signflag=true;
                                        zeroflag=false;
                                    } else if (DX==0) {
                                        signflag=false;
                                        zeroflag=true;
                                    }else {
                                        signflag=false;
                                        zeroflag=false;
                                    }
                                }
                            }
                        }
                        else if (satir.startsWith("BOL ") ) {
                            //Bölme
                            String[] bolme = parcala(satir);
                            if(bolme[1].equals("AX")){
                                if(bolme[2].equals("AX") ){
                                    AX=AX/AX;
                                } else if(bolme[2].equals("BX") ){
                                    AX=AX/BX;
                                } else if (bolme[2].equals("CX") ){
                                    AX=AX/CX;
                                } else if (bolme[2].equals("DX") ){
                                    AX=AX/DX;
                                }else{
                                    AX=AX/Integer.parseInt(bolme[2]);
                                }
                            }
                            else if(bolme[1].equals("BX")){
                                if(bolme[2].equals("AX") ){
                                    BX=BX/AX;
                                }else if(bolme[2].equals("BX") ){
                                    BX=BX/BX;
                                } else if (bolme[2].equals("CX") ){
                                    BX=BX/CX;
                                } else if (bolme[2].equals("DX") ){
                                    BX=BX/DX;
                                }else{
                                    BX=BX/Integer.parseInt(bolme[2]);
                                }
                            }
                            else if(bolme[1].equals("CX")){
                                if(bolme[2].equals("AX") ){
                                    CX=CX/AX;
                                } else if (bolme[2].equals("BX") ){
                                    CX=CX/BX;
                                }else if(bolme[2].equals("CX") ){
                                    CX=CX/CX;
                                } else if (bolme[2].equals("DX") ){
                                    CX=CX/DX;
                                }else{
                                    CX=CX/Integer.parseInt(bolme[2]);
                                }
                            }
                            else if(bolme[1].equals("DX")){
                                if(bolme[2].equals("AX") ){
                                    DX=DX/AX;
                                } else if (bolme[2].equals("BX") ){
                                    DX=DX/BX;
                                } else if (bolme[2].equals("CX") ){
                                    DX=DX/CX;
                                }else if (bolme[2].equals("DX") ){
                                    DX=DX/DX;
                                }else{
                                    DX=DX/Integer.parseInt(bolme[2]);
                                }
                            }
                        }
                        else if (satir.startsWith("CRP ") ) {
                            //Çarpma
                            String[] carpma = parcala(satir);
                            if(carpma[1].equals("AX")){
                                if(carpma[2].equals("AX") ){
                                    AX=AX*AX;
                                } else if(carpma[2].equals("BX") ){
                                    AX=AX*BX;
                                } else if (carpma[2].equals("CX") ){
                                    AX=AX*CX;
                                } else if (carpma[2].equals("DX") ){
                                    AX=AX*DX;
                                }else{
                                    AX=AX*Integer.parseInt(carpma[2]);
                                }
                            }
                            else if(carpma[1].equals("BX")){
                                if(carpma[2].equals("AX") ){
                                    BX=BX*AX;
                                }else if(carpma[2].equals("BX") ){
                                    BX=BX*BX;
                                } else if (carpma[2].equals("CX") ){
                                    BX=BX*CX;
                                } else if (carpma[2].equals("DX") ){
                                    BX=BX*DX;
                                }else{
                                    BX=BX*Integer.parseInt(carpma[2]);
                                }
                            }
                            else if(carpma[1].equals("CX")){
                                if(carpma[2].equals("AX") ){
                                    CX=CX*AX;
                                } else if (carpma[2].equals("BX") ){
                                    CX=CX*BX;
                                }else if(carpma[2].equals("CX") ){
                                    CX=CX*CX;
                                } else if (carpma[2].equals("DX") ){
                                    CX=CX*DX;
                                }else{
                                    CX=CX*Integer.parseInt(carpma[2]);
                                }
                            }
                            else if(carpma[1].equals("DX")){
                                if(carpma[2].equals("AX") ){
                                    DX=DX*AX;
                                } else if (carpma[2].equals("BX") ){
                                    DX=DX*BX;
                                } else if (carpma[2].equals("CX") ){
                                    DX=DX*CX;
                                }else if (carpma[2].equals("DX") ){
                                    DX=DX*DX;
                                }else{
                                    DX=DX*Integer.parseInt(carpma[2]);
                                }
                            }
                        }
                        else if (satir.startsWith("HRK ") ) {

                            //Atama
                            String[] atama = parcala(satir);

                            if(atama[1].equals("AX")){
                                if(atama[2].equals("BX") ){
                                    AX=BX;
                                } else if (atama[2].equals("CX") ){
                                    AX=CX;
                                } else if (atama[2].equals("DX") ){
                                    AX=DX;
                                }else{
                                    AX=Integer.parseInt(atama[2]);
                                }
                            }else if(atama[1].equals("BX")){
                                if(atama[2].equals("AX") ){
                                    BX=AX;
                                } else if (atama[2].equals("CX") ){
                                    BX=CX;
                                } else if (atama[2].equals("DX") ){
                                    BX=DX;
                                }else{
                                    BX=Integer.parseInt(atama[2]);
                                }
                            }else if(atama[1].equals("CX")){
                                if(atama[2].equals("AX") ){
                                    CX=AX;
                                } else if (atama[2].equals("BX") ){
                                    CX=BX;
                                } else if (atama[2].equals("DX") ){
                                    CX=DX;
                                }else{
                                    CX=Integer.parseInt(atama[2]);
                                }
                            }else if(atama[1].equals("DX")){
                                if(atama[2].equals("AX") ){
                                    DX=AX;
                                } else if (atama[2].equals("BX") ){
                                    DX=BX;
                                } else if (atama[2].equals("CX") ){
                                    DX=CX;
                                }else{
                                    DX=Integer.parseInt(atama[2]);
                                }
                            }
                        }
                        else if (satir.startsWith("VE ") ) {
                            //VE
                            String[] ve = parcala(satir);
                            if(ve[1].equals("AX")){
                                if(ve[2].equals("AX") ){
                                    AX=AX & AX;
                                } else if(ve[2].equals("BX") ){
                                    AX=AX & BX;
                                } else if (ve[2].equals("CX") ){
                                    AX=AX & CX;
                                } else if (ve[2].equals("DX") ){
                                    AX=AX & DX;
                                }else{
                                    AX=AX & Integer.parseInt(ve[2]);
                                }
                            }
                            else if(ve[1].equals("BX")){
                                if(ve[2].equals("AX") ){
                                    BX=BX & AX;
                                }else if(ve[2].equals("BX") ){
                                    BX=BX & BX;
                                } else if (ve[2].equals("CX") ){
                                    BX=BX & CX;
                                } else if (ve[2].equals("DX") ){
                                    BX=BX & DX;
                                }else{
                                    BX=BX & Integer.parseInt(ve[2]);
                                }
                            }
                            else if(ve[1].equals("CX")){
                                if(ve[2].equals("AX") ){
                                    CX=CX & AX;
                                } else if (ve[2].equals("BX") ){
                                    CX=CX & BX;
                                }else if(ve[2].equals("CX") ){
                                    CX=CX & CX;
                                } else if (ve[2].equals("DX") ){
                                    CX=CX & DX;
                                }else{
                                    CX=CX & Integer.parseInt(ve[2]);
                                }
                            }
                            else if(ve[1].equals("DX")){
                                if(ve[2].equals("AX") ){
                                    DX=DX & AX;
                                } else if (ve[2].equals("BX") ){
                                    DX=DX & BX;
                                } else if (ve[2].equals("CX") ){
                                    DX=DX & CX;
                                }else if (ve[2].equals("DX") ){
                                    DX=DX & DX;
                                }else{
                                    DX=DX & Integer.parseInt(ve[2]);
                                }
                            }
                        }
                        else if (satir.startsWith("VEY ")) {
                            //VEYA
                            String[] ve = parcala(satir);
                            if(ve[1].equals("AX")){
                                if(ve[2].equals("AX") ){
                                    AX=AX | AX;
                                } else if(ve[2].equals("BX") ){
                                    AX=AX | BX;
                                } else if (ve[2].equals("CX") ){
                                    AX=AX | CX;
                                } else if (ve[2].equals("DX") ){
                                    AX=AX | DX;
                                }else{
                                    AX=AX | Integer.parseInt(ve[2]);
                                }
                            }
                            else if(ve[1].equals("BX")){
                                if(ve[2].equals("AX") ){
                                    BX=BX | AX;
                                }else if(ve[2].equals("BX") ){
                                    BX=BX | BX;
                                } else if (ve[2].equals("CX") ){
                                    BX=BX | CX;
                                } else if (ve[2].equals("DX") ){
                                    BX=BX | DX;
                                }else{
                                    BX=BX | Integer.parseInt(ve[2]);
                                }
                            }
                            else if(ve[1].equals("CX")){
                                if(ve[2].equals("AX") ){
                                    CX=CX | AX;
                                } else if (ve[2].equals("BX") ){
                                    CX=CX | BX;
                                }else if(ve[2].equals("CX") ){
                                    CX=CX | CX;
                                } else if (ve[2].equals("DX") ){
                                    CX=CX | DX;
                                }else{
                                    CX=CX | Integer.parseInt(ve[2]);
                                }
                            }
                            else if(ve[1].equals("DX")){
                                if(ve[2].equals("AX") ){
                                    DX=DX | AX;
                                } else if (ve[2].equals("BX") ){
                                    DX=DX | BX;
                                } else if (ve[2].equals("CX") ){
                                    DX=DX | CX;
                                }else if (ve[2].equals("DX") ){
                                    DX=DX | DX;
                                }else{
                                    DX=DX | Integer.parseInt(ve[2]);
                                }
                            }
                        }
                        else if (satir.startsWith("DEG ") ) {

                            //DEG
                            String[] deg = parcala(satir);

                            if(deg[1].equals("AX")){
                                AX=Integer.MAX_VALUE-AX;
                            }else if(deg[1].equals("BX")){
                                BX=Integer.MAX_VALUE-BX;
                            }else if(deg[1].equals("CX")){
                                CX=Integer.MAX_VALUE-CX;
                            }else if(deg[1].equals("DX")){
                                DX=Integer.MAX_VALUE-DX;
                            }
                        }
                        else if (satir.startsWith("OKU ") ) {
                            //OKU
                            String[] okuma = parcala(satir);
                            System.out.print("\n"+okuma[1]+" degerini girin: ");
                            if(okuma[1].equals("AX")){
                                AX=scanner.nextInt();
                            }else if(okuma[1].equals("BX")){
                                BX=scanner.nextInt();
                            }else if(okuma[1].equals("CX")){
                                CX=scanner.nextInt();
                            }else if(okuma[1].equals("DX")){
                                DX=scanner.nextInt();
                            }
                        }
                        else if (satir.startsWith("YAZ ")) {
                            //YAZ
                            String[] atama = parcala(satir);

                            if(atama[1].equals("AX")){
                                System.out.println("AX="+AX);
                            }
                            else if(atama[1].equals("BX")){
                                System.out.println("BX="+BX);
                            }
                            else if(atama[1].equals("CX")){
                                System.out.println("CX="+CX);
                            }
                            else if(atama[1].equals("DX")){
                                System.out.println("DX="+DX);
                            }
                        }
                    }else{
                        continue;
                    }
                }else{
                    continue;
                }
            }
            else{
                if (satir.startsWith("TOP ") ) {
                    //Toplama
                    String[] toplama = parcala(satir);
                    if(toplama[1].equals("AX")){
                        if(toplama[2].equals("AX") ){
                            AX=AX+AX;
                        } else if(toplama[2].equals("BX") ){
                            AX=AX+BX;
                        } else if (toplama[2].equals("CX") ){
                            AX=AX+CX;
                        } else if (toplama[2].equals("DX") ){
                            AX=AX+DX;
                        }else{
                            AX=AX+Integer.parseInt(toplama[2]);
                        }
                    }
                    else if(toplama[1].equals("BX")){
                        if(toplama[2].equals("AX") ){
                            BX=BX+AX;
                        }else if(toplama[2].equals("BX") ){
                            BX=BX+BX;
                        } else if (toplama[2].equals("CX") ){
                            BX=BX+CX;
                        } else if (toplama[2].equals("DX") ){
                            BX=BX+DX;
                        }else{
                            BX=BX+Integer.parseInt(toplama[2]);
                        }
                    }
                    else if(toplama[1].equals("CX")){
                        if(toplama[2].equals("AX") ){
                            CX=CX+AX;
                        } else if (toplama[2].equals("BX") ){
                            CX=CX+BX;
                        }else if(toplama[2].equals("CX") ){
                            CX=CX+CX;
                        } else if (toplama[2].equals("DX") ){
                            CX=CX+DX;
                        }else{
                            CX=CX+Integer.parseInt(toplama[2]);
                        }
                    }
                    else if(toplama[1].equals("DX")){
                        if(toplama[2].equals("AX") ){
                            DX=DX+AX;
                        } else if (toplama[2].equals("BX") ){
                            DX=DX+BX;
                        } else if (toplama[2].equals("CX") ){
                            DX=DX+CX;
                        }else if (toplama[2].equals("DX") ){
                            DX=DX+DX;
                        }else{
                            DX=DX+Integer.parseInt(toplama[2]);
                        }
                    }
                }
                else if (satir.startsWith("CIK ") ) {
                    //Çıkartma
                    String[] cikartma = parcala(satir);
                    if(cikartma[1].equals("AX")){
                        if(cikartma[2].equals("AX") ){
                            AX=AX-AX;
                            if(AX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (AX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        } else if(cikartma[2].equals("BX") ){
                            AX=AX-BX;
                            if(AX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (AX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        } else if (cikartma[2].equals("CX") ){
                            AX=AX-CX;
                            if(AX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (AX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        } else if (cikartma[2].equals("DX") ){
                            AX=AX-DX;
                            if(AX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (AX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        }else{
                            AX=AX-Integer.parseInt(cikartma[2]);
                            if(AX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (AX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        }
                    }
                    else if(cikartma[1].equals("BX")){
                        if(cikartma[2].equals("AX") ){
                            BX=BX-AX;
                            if(BX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (BX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        }else if(cikartma[2].equals("BX") ){
                            BX=BX-BX;
                            if(BX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (BX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        } else if (cikartma[2].equals("CX") ){
                            BX=BX-CX;
                            if(BX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (BX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        } else if (cikartma[2].equals("DX") ){
                            BX=BX-DX;
                            if(BX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (BX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        }else{
                            BX=BX-Integer.parseInt(cikartma[2]);
                            if(BX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (BX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        }
                    }
                    else if(cikartma[1].equals("CX")){
                        if(cikartma[2].equals("AX") ){
                            CX=CX-AX;
                            if(CX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (CX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        } else if (cikartma[2].equals("BX") ){
                            CX=CX-BX;
                            if(CX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (CX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        }else if(cikartma[2].equals("CX") ){
                            CX=CX-CX;
                            if(CX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (CX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        } else if (cikartma[2].equals("DX") ){
                            CX=CX-DX;
                            if(CX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (CX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        }else{
                            CX=CX-Integer.parseInt(cikartma[2]);
                            if(CX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (CX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        }
                    }
                    else if(cikartma[1].equals("DX")){
                        if(cikartma[2].equals("AX") ){
                            DX=DX-AX;
                            if(DX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (DX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        } else if (cikartma[2].equals("BX") ){
                            DX=DX-BX;
                            if(DX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (DX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        } else if (cikartma[2].equals("CX") ){
                            DX=DX-CX;
                            if(DX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (DX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        }else if (cikartma[2].equals("DX") ){
                            DX=DX-DX;
                            if(DX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (DX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        }else{
                            DX=DX-Integer.parseInt(cikartma[2]);
                            if(DX<0){
                                signflag=true;
                                zeroflag=false;
                            } else if (DX==0) {
                                signflag=false;
                                zeroflag=true;
                            }else {
                                signflag=false;
                                zeroflag=false;
                            }
                        }
                    }
                }
                else if (satir.startsWith("BOL ") ) {
                    //Bölme
                    String[] bolme = parcala(satir);
                    if(bolme[1].equals("AX")){
                        if(bolme[2].equals("AX") ){
                            AX=AX/AX;
                        } else if(bolme[2].equals("BX") ){
                            AX=AX/BX;
                        } else if (bolme[2].equals("CX") ){
                            AX=AX/CX;
                        } else if (bolme[2].equals("DX") ){
                            AX=AX/DX;
                        }else{
                            AX=AX/Integer.parseInt(bolme[2]);
                        }
                    }
                    else if(bolme[1].equals("BX")){
                        if(bolme[2].equals("AX") ){
                            BX=BX/AX;
                        }else if(bolme[2].equals("BX") ){
                            BX=BX/BX;
                        } else if (bolme[2].equals("CX") ){
                            BX=BX/CX;
                        } else if (bolme[2].equals("DX") ){
                            BX=BX/DX;
                        }else{
                            BX=BX/Integer.parseInt(bolme[2]);
                        }
                    }
                    else if(bolme[1].equals("CX")){
                        if(bolme[2].equals("AX") ){
                            CX=CX/AX;
                        } else if (bolme[2].equals("BX") ){
                            CX=CX/BX;
                        }else if(bolme[2].equals("CX") ){
                            CX=CX/CX;
                        } else if (bolme[2].equals("DX") ){
                            CX=CX/DX;
                        }else{
                            CX=CX/Integer.parseInt(bolme[2]);
                        }
                    }
                    else if(bolme[1].equals("DX")){
                        if(bolme[2].equals("AX") ){
                            DX=DX/AX;
                        } else if (bolme[2].equals("BX") ){
                            DX=DX/BX;
                        } else if (bolme[2].equals("CX") ){
                            DX=DX/CX;
                        }else if (bolme[2].equals("DX") ){
                            DX=DX/DX;
                        }else{
                            DX=DX/Integer.parseInt(bolme[2]);
                        }
                    }
                }
                else if (satir.startsWith("CRP ") ) {
                    //Çarpma
                    String[] carpma = parcala(satir);
                    if(carpma[1].equals("AX")){
                        if(carpma[2].equals("AX") ){
                            AX=AX*AX;
                        } else if(carpma[2].equals("BX") ){
                            AX=AX*BX;
                        } else if (carpma[2].equals("CX") ){
                            AX=AX*CX;
                        } else if (carpma[2].equals("DX") ){
                            AX=AX*DX;
                        }else{
                            AX=AX*Integer.parseInt(carpma[2]);
                        }
                    }
                    else if(carpma[1].equals("BX")){
                        if(carpma[2].equals("AX") ){
                            BX=BX*AX;
                        }else if(carpma[2].equals("BX") ){
                            BX=BX*BX;
                        } else if (carpma[2].equals("CX") ){
                            BX=BX*CX;
                        } else if (carpma[2].equals("DX") ){
                            BX=BX*DX;
                        }else{
                            BX=BX*Integer.parseInt(carpma[2]);
                        }
                    }
                    else if(carpma[1].equals("CX")){
                        if(carpma[2].equals("AX") ){
                            CX=CX*AX;
                        } else if (carpma[2].equals("BX") ){
                            CX=CX*BX;
                        }else if(carpma[2].equals("CX") ){
                            CX=CX*CX;
                        } else if (carpma[2].equals("DX") ){
                            CX=CX*DX;
                        }else{
                            CX=CX*Integer.parseInt(carpma[2]);
                        }
                    }
                    else if(carpma[1].equals("DX")){
                        if(carpma[2].equals("AX") ){
                            DX=DX*AX;
                        } else if (carpma[2].equals("BX") ){
                            DX=DX*BX;
                        } else if (carpma[2].equals("CX") ){
                            DX=DX*CX;
                        }else if (carpma[2].equals("DX") ){
                            DX=DX*DX;
                        }else{
                            DX=DX*Integer.parseInt(carpma[2]);
                        }
                    }
                }
                else if (satir.startsWith("D ") || satir.startsWith("DB ") ||
                        satir.startsWith("DK ") || satir.startsWith("DKE ") || satir.startsWith("DBE ") ||
                        satir.startsWith("DED ") || satir.startsWith("DE ") ) {
                    //Dallanma
                    if(satir.startsWith("D ")){
                        atlansinmi=true;
                        String[] atama = parcala(satir);
                        atlanacaketiket=atama[1];
                    } else if (satir.startsWith("DB ")) {
                        if(signflag==false && zeroflag==false){
                            atlansinmi=true;
                            String[] atama = parcala(satir);
                            atlanacaketiket=atama[1];
                        }
                    }else if (satir.startsWith("DK ")) {
                        if(signflag==true && zeroflag==false){
                            atlansinmi=true;
                            String[] atama = parcala(satir);
                            atlanacaketiket=atama[1];
                        }
                    }else if (satir.startsWith("DKE ")) {
                        if(signflag==true || zeroflag==true){
                            atlansinmi=true;
                            String[] atama = parcala(satir);
                            atlanacaketiket=atama[1];
                        }
                    }else if (satir.startsWith("DBE ")) {
                        if(signflag==false || zeroflag==true){
                            atlansinmi=true;
                            String[] atama = parcala(satir);
                            atlanacaketiket=atama[1];
                        }
                    }else if (satir.startsWith("DED ")) {
                        if(zeroflag==false){
                            atlansinmi=true;
                            String[] atama = parcala(satir);
                            atlanacaketiket=atama[1];
                        }
                    }else if (satir.startsWith("DE ")) {
                        if(zeroflag==true){
                            atlansinmi=true;
                            String[] atama = parcala(satir);
                            atlanacaketiket=atama[1];
                        }
                    }

                }
                else if (satir.startsWith("HRK ") ) {

                    //Atama
                    String[] atama = parcala(satir);

                    if(atama[1].equals("AX")){
                        if(atama[2].equals("BX") ){
                            AX=BX;
                        } else if (atama[2].equals("CX") ){
                            AX=CX;
                        } else if (atama[2].equals("DX") ){
                            AX=DX;
                        }else{
                            AX=Integer.parseInt(atama[2]);
                        }
                    }else if(atama[1].equals("BX")){
                        if(atama[2].equals("AX") ){
                            BX=AX;
                        } else if (atama[2].equals("CX") ){
                            BX=CX;
                        } else if (atama[2].equals("DX") ){
                            BX=DX;
                        }else{
                            BX=Integer.parseInt(atama[2]);
                        }
                    }else if(atama[1].equals("CX")){
                        if(atama[2].equals("AX") ){
                            CX=AX;
                        } else if (atama[2].equals("BX") ){
                            CX=BX;
                        } else if (atama[2].equals("DX") ){
                            CX=DX;
                        }else{
                            CX=Integer.parseInt(atama[2]);
                        }
                    }else if(atama[1].equals("DX")){
                        if(atama[2].equals("AX") ){
                            DX=AX;
                        } else if (atama[2].equals("BX") ){
                            DX=BX;
                        } else if (atama[2].equals("CX") ){
                            DX=CX;
                        }else{
                            DX=Integer.parseInt(atama[2]);
                        }
                    }
                }
                else if (satir.startsWith("VE ") ) {
                    //VE
                    String[] ve = parcala(satir);
                    if(ve[1].equals("AX")){
                        if(ve[2].equals("AX") ){
                            AX=AX & AX;
                        } else if(ve[2].equals("BX") ){
                            AX=AX & BX;
                        } else if (ve[2].equals("CX") ){
                            AX=AX & CX;
                        } else if (ve[2].equals("DX") ){
                            AX=AX & DX;
                        }else{
                            AX=AX & Integer.parseInt(ve[2]);
                        }
                    }
                    else if(ve[1].equals("BX")){
                        if(ve[2].equals("AX") ){
                            BX=BX & AX;
                        }else if(ve[2].equals("BX") ){
                            BX=BX & BX;
                        } else if (ve[2].equals("CX") ){
                            BX=BX & CX;
                        } else if (ve[2].equals("DX") ){
                            BX=BX & DX;
                        }else{
                            BX=BX & Integer.parseInt(ve[2]);
                        }
                    }
                    else if(ve[1].equals("CX")){
                        if(ve[2].equals("AX") ){
                            CX=CX & AX;
                        } else if (ve[2].equals("BX") ){
                            CX=CX & BX;
                        }else if(ve[2].equals("CX") ){
                            CX=CX & CX;
                        } else if (ve[2].equals("DX") ){
                            CX=CX & DX;
                        }else{
                            CX=CX & Integer.parseInt(ve[2]);
                        }
                    }
                    else if(ve[1].equals("DX")){
                        if(ve[2].equals("AX") ){
                            DX=DX & AX;
                        } else if (ve[2].equals("BX") ){
                            DX=DX & BX;
                        } else if (ve[2].equals("CX") ){
                            DX=DX & CX;
                        }else if (ve[2].equals("DX") ){
                            DX=DX & DX;
                        }else{
                            DX=DX & Integer.parseInt(ve[2]);
                        }
                    }
                }
                else if (satir.startsWith("VEY ")) {
                    //VEYA
                    String[] ve = parcala(satir);
                    if(ve[1].equals("AX")){
                        if(ve[2].equals("AX") ){
                            AX=AX | AX;
                        } else if(ve[2].equals("BX") ){
                            AX=AX | BX;
                        } else if (ve[2].equals("CX") ){
                            AX=AX | CX;
                        } else if (ve[2].equals("DX") ){
                            AX=AX | DX;
                        }else{
                            AX=AX | Integer.parseInt(ve[2]);
                        }
                    }
                    else if(ve[1].equals("BX")){
                        if(ve[2].equals("AX") ){
                            BX=BX | AX;
                        }else if(ve[2].equals("BX") ){
                            BX=BX | BX;
                        } else if (ve[2].equals("CX") ){
                            BX=BX | CX;
                        } else if (ve[2].equals("DX") ){
                            BX=BX | DX;
                        }else{
                            BX=BX | Integer.parseInt(ve[2]);
                        }
                    }
                    else if(ve[1].equals("CX")){
                        if(ve[2].equals("AX") ){
                            CX=CX | AX;
                        } else if (ve[2].equals("BX") ){
                            CX=CX | BX;
                        }else if(ve[2].equals("CX") ){
                            CX=CX | CX;
                        } else if (ve[2].equals("DX") ){
                            CX=CX | DX;
                        }else{
                            CX=CX | Integer.parseInt(ve[2]);
                        }
                    }
                    else if(ve[1].equals("DX")){
                        if(ve[2].equals("AX") ){
                            DX=DX | AX;
                        } else if (ve[2].equals("BX") ){
                            DX=DX | BX;
                        } else if (ve[2].equals("CX") ){
                            DX=DX | CX;
                        }else if (ve[2].equals("DX") ){
                            DX=DX | DX;
                        }else{
                            DX=DX | Integer.parseInt(ve[2]);
                        }
                    }
                }
                else if (satir.startsWith("DEG ") ) {

                    //DEG
                    String[] deg = parcala(satir);

                    if(deg[1].equals("AX")){
                        AX=Integer.MAX_VALUE-AX;
                    }else if(deg[1].equals("BX")){
                        BX=Integer.MAX_VALUE-BX;
                    }else if(deg[1].equals("CX")){
                        CX=Integer.MAX_VALUE-CX;
                    }else if(deg[1].equals("DX")){
                        DX=Integer.MAX_VALUE-DX;
                    }
                }
                else if (satir.startsWith("OKU ") ) {
                    //OKU
                    String[] okuma = parcala(satir);
                    System.out.print("\n"+okuma[1]+" degerini girin: ");
                    if(okuma[1].equals("AX")){
                        AX=scanner.nextInt();
                    }else if(okuma[1].equals("BX")){
                        BX=scanner.nextInt();
                    }else if(okuma[1].equals("CX")){
                        CX=scanner.nextInt();
                    }else if(okuma[1].equals("DX")){
                        DX=scanner.nextInt();
                    }
                }
                else if (satir.startsWith("YAZ ")) {
                    //YAZ
                    String[] atama = parcala(satir);

                    if(atama[1].equals("AX")){
                        System.out.println("AX="+AX);
                    }
                    else if(atama[1].equals("BX")){
                        System.out.println("BX="+BX);
                    }
                    else if(atama[1].equals("CX")){
                        System.out.println("CX="+CX);
                    }
                    else if(atama[1].equals("DX")){
                        System.out.println("DX="+DX);
                    }
                }
            }
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
            hatabul(i,satir);
            i++;
        }
        if (hatavardir!=true){
            System.out.println("Hata yok");
            //execution1 Çalıştı
            execution(satirlar);
        }else{
            System.out.println("Hata oldugu icin calistirilamadi");
        }
        scanner.close();
    }
}
