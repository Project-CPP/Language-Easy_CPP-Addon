# What I ask of you.
Feel free to use Language-Easy in your C++ projects and feel free to fork and build more out of this. All I ask... PLEASE FORK... DON'T COPY WITHOUT SHOWING WHO HAS CREATED WHAT... This way people can see your work toward someone else's work. People will look down on you for not doing that. Github keeps records on who created it first. So go figure on that, if you are a thief. Otherwise feel free to take advantage of what I put out there for you!

# Windows Syntax.

## Windows Message Box
#### **Class Object Creation**

Syntax Example.... ```WindowsMessage YourMessageObject (" Your window name. " , " Your Window Message "); ```

Example .... ```WindowsMessage HeyJacob (" Greeting to Jacob " , " Hello there Jacob!" );```

#### **Class Object Methods**

1.  ____________________OutputWindow ____________________

Syntax Example.... ```YourMessageObject.OutputWindow();```

Example.... ```HeyJacob.OutputWindow();```

#### **Overall Code**
    WindowsMessage YourMessageObject(" Your window name. ", " Your Window Message ");

    WindowsMessage HeyJacob(" Greeting to Jacob ", " Hello there Jacob!");

    YourMessageObject.OutputWindow();

    HeyJacob.OutputWindow();

#### **Example Output**
![alt tag](http://i347.photobucket.com/albums/p468/Jacob_Muncy_0/Capture5_zpsvyve8prw.png)

![alt tag](http://i347.photobucket.com/albums/p468/Jacob_Muncy_0/Capture6_zpswjey0quk.png)
## Windows Battery
#### **Class Object Creation**

Syntax Example .... ```WindowsBattery ObjectName (Is battery present true or false);```

Example .... ```WindowsBattery Battery(true);```

#### **Class Object Methods**

(1.)  ____________________ Output_Battery_Percentage_As_String ____________________

Syntax Example.... ```YourBatteryObject.Output_Battery_Percentage_As_String();```

Example.... ```Battery.Output_Battery_Percentage_As_String();```

(2.)  ____________________ Output_Battery_Percentage_As_Double ____________________

Syntax Example.... ```YourBatteryObject.Output_Battery_Percentage_As_Double();```

Example.... ```Battery.Output_Battery_Percentage_As_Double();```

(3.)  ____________________ Output_Battery_Percentage_As_Integer ____________________

Syntax Example.... ```YourBatteryObject.Output_Battery_Percentage_As_Integer();```

Example.... ```Battery.Output_Battery_Percentage_As_Integer();```

#### **Overall Code**

    WindowsBattery Battery(true);
  
	 cout << "Battery Percent as a String %" << Battery.Output_Battery_Percentage_As_String() << endl;
	 cout << "Battery Percent as a Double %" << Battery.Output_Battery_Percentage_As_Double() << endl;
	 cout << "Battery Percent as a Integer %" << Battery.Output_Battery_Percentage_As_Integer() << endl;
	
    cin.get();
    
#### **Example Output**
![alt tag](http://i347.photobucket.com/albums/p468/Jacob_Muncy_0/Capture8_zpsn5wiibkr.png)
