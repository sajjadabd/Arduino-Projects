Serial.print("UID Tag : ");

String content = "";
byte letter ;

for( byte i = 0 ; i <mfrc522.uid.size ; i++)
{
	Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
	Serial.print(mfrc522.uid.uidByte[i], HEX);
	
	content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
	content.concat(String(mfrc522.uid.uidByte[i], HEX));
}

Serial.println();
Serial.print("Message : ");
content.toUppercase();

if(content.substring(1) = "XX XX XX XX")
{
	Serial.println("Welcome to Your Box");
	delay(1000);
}

else
{
	Serial.println("You Can't Access to This Box");
	delay(1000);
}