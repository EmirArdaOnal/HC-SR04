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
