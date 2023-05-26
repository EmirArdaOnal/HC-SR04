# HC-SR04
Buzzer sounding by distance using HC-SR04

1. Gerekli Malzemeler:
   - Arduino (örneğin Arduino Uno)
   - HC-SR04 mesafe sensörü
   - Buzzer
   - Düz kablolar veya erkek-dişi jumper kabloları
   - Breadboard (isteğe bağlı, bağlantıları düzenlemek için kullanılabilir)

2. Bağlantılar:
   HC-SR04 sensörünün ve buzzerin pinlerini Arduino'ya bağlamak için aşağıdaki adımları takip edin:

   a. HC-SR04 Sensör Bağlantıları:
      - VCC bağlantısı: HC-SR04 sensöründeki VCC pini, Arduino'dan güç almak için kullanılır. Bu pini Arduino'nun 5V pinine bağlayabilirsiniz.
      - GND bağlantısı: HC-SR04 sensöründeki GND pini, Arduino'nun GND pinine bağlanmalıdır.
      - Trig bağlantısı: HC-SR04 sensöründeki Trig pini, Arduino'daki bir dijital çıkış pinine bağlanmalıdır. Örneğin, Arduino'daki D2 pinini Trig piniyle bağlayabilirsiniz.
      - Echo bağlantısı: HC-SR04 sensöründeki Echo pini, Arduino'daki bir dijital giriş pinine bağlanmalıdır. Örneğin, Arduino'daki D3 pinini Echo piniyle bağlayabilirsiniz.

   b. Buzzer Bağlantısı:
      - Buzzerin pozitif (+) pini, Arduino'daki bir dijital çıkış pinine bağlanmalıdır. Örneğin, Arduino'daki D4 pinini buzzerin pozitif piniyle bağlayabilirsiniz.
      - Buzzerin negatif (-) pini, Arduino'nun GND pinine bağlanmalıdır.

3. Kodu Yükleyin:
   Arduino IDE veya benzeri bir yazılım kullanarak, HC-SR04 sensörü ve buzzer için gerekli kodu yazın ve Arduino'ya yükleyin. Bu kod, sensörden mesafe ölçecek ve mesafeye göre buzzerin sesini kontrol edecektir.

4. Güç Verin:
   Arduino'yu bir güç kaynağına (USB bağlantısı veya harici güç kaynağı) bağlayarak devreyi çalıştırın.



Bu kod, Arduino platformunda HC-SR04 mesafe sensörü ve bir buzzer kullanarak mesafe ölçümü yapar ve buna bağlı olarak buzzerin sesini kontrol eder:

1. `setup()` fonksiyonu, başlangıç ayarlarını yapmak için sadece bir kez çalışır. Bu ayarlar arasında pin modlarının belirlenmesi ve seri haberleşmenin başlatılması bulunur.

2. `loop()` fonksiyonu, sürekli olarak tekrarlanır ve ana işlevi gerçekleştirir.

3. İlk olarak, `sure` ve `mesafe` adında iki değişken tanımlanır. `sure`, sensörden dönen yankının süresini ölçmek için kullanılacak, `mesafe` ise ölçülen mesafeyi tutacak değişkendir.

4. `trigPin` (Trigger pini) Arduino'da çıkış olarak ayarlanır ve bir mikro saniye boyunca düşük seviyeye ayarlanır. Bu işlem, sensöre tetikleme sinyali göndermek için yapılır.

5. Ardından, `trigPin` yüksek seviyeye ayarlanır ve 10 mikro saniye beklenir. Bu işlem, sensörün yankıyı göndermesi için gerekli sinyali almasını sağlar.

6. `trigPin` tekrar düşük seviyeye ayarlanır.

7. `pulseIn()` fonksiyonu kullanılarak `echoPin` (Echo pini) üzerindeki yüksek süresi (`sure`) ölçülür. Bu süre, yankının sensöre geri dönmesi ve Arduino tarafından algılanması için geçen süreyi temsil eder.

8. Elde edilen süre (`sure`), sensör ile ölçülen mesafeye dönüştürülür. Bu dönüşüm için kullanılan formül, süreyi 58.2'ye bölmektir.

9. Seri port üzerinden ölçülen mesafeyi görüntülemek için `Serial.print()` ve `Serial.println()` komutları kullanılır.

10. Ardından, ölçülen mesafe, belirlenen eşik değerlere göre buzzerin sesini kontrol etmek için `if-else if-else` yapılarıyla kontrol edilir.

11. Eğer ölçülen mesafe `mesafeEşikYakın` değerinden küçükse, buzzerin frekansı 1000 olarak ayarlanır ve yüksek bir ses çıkarır.

12. Eğer ölçülen mesafe `mesafeEşikOrta` değerinden küçükse, buzzerin frekansı 500 olarak ayarlanır ve orta bir ses çıkarır.

13. Eğer ölçülen mesafe `mesafeEşikUzak` değerinden küçükse, buzzerin frekansı 200 olarak ayarlanır ve düşük bir ses çıkarır.

14. Eğer ölçülen mesafe belirlenen eşik değerlerinin hiçbirine uymuyorsa, buzzer kapatılır.

15. `delay()` fonksiyonu, ölçüm aralığını kontrol etmek için 100 milisaniye gecikme ekler. Bu, ardışık ölçümler arasında beklenen süreyi sağlar.

16. İşlem başa döner ve sürekli olarak mesafe ölçümü ve buzzer kontrolü yapılır.

Bu şekilde, HC-SR04 mesafe sensörü kullanılarak ölçülen mesafe değerine göre buzzerin sesi kontrol edilmiş olur.
