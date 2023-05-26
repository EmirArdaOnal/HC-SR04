// HC-SR04 Mesafe Sensörü
const int trigPin = 2; // Trigger pini
const int echoPin = 3; // Echo pini

// Buzzer
const int buzzerPin = 4; // Buzzer pini

// Mesafe eşik değerleri (cm)
const int mesafeEşikYakın = 30;
const int mesafeEşikOrta = 50;
const int mesafeEşikUzak = 70;

void setup() {
  // Pin ayarları
  pinMode(trigPin, OUTPUT); // Trigger pini çıkış olarak ayarlanır
  pinMode(echoPin, INPUT); // Echo pini giriş olarak ayarlanır
  pinMode(buzzerPin, OUTPUT); // Buzzer pini çıkış olarak ayarlanır
  
  // Seri haberleşme başlatılıyor
  Serial.begin(9600); // Seri haberleşme hızı 9600 baud olarak ayarlanır
}

void loop() {
  // Mesafeyi ölç
  long sure, mesafe; //32 bitlik veri
  digitalWrite(trigPin, LOW); // Trigger pini düşük seviyeye ayarlanır
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Trigger pini yüksek seviyeye ayarlanır
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // Trigger pini tekrar düşük seviyeye ayarlanır
  sure = pulseIn(echoPin, HIGH); // Echo pini üzerindeki süreyi ölçer
  mesafe = sure / 58.2; // Hesaplama formülü: Süre / 58.2 ile mesafeyi hesaplar

  // Mesafeyi seri porttan oku
  Serial.print("Mesafe: ");
  Serial.print(mesafe);
  Serial.println(" cm");

  // Mesafe eşik değerlerine göre buzzer sesini kontrol et
  if (mesafe < mesafeEşikYakın) {
    // Buzzer sesini yüksek yap
    tone(buzzerPin, 1000);
  } else if (mesafe < mesafeEşikOrta) {
    // Buzzer sesini orta yap
    tone(buzzerPin, 500);
  } else if (mesafe < mesafeEşikUzak) {
    // Buzzer sesini düşük yap
    tone(buzzerPin, 200);
  } else {
    // Buzzeri kapat
    noTone(buzzerPin);
  }
  
  delay(100); // Ölçüm aralığını kontrol etmek için gecikme ekle
}
