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
![alt tag](https://lh3.googleusercontent.com/iJD4aH1VEltoAYLne5nQsFVlzyDkscR_D9H6p4xSC_qVWUvhv7dstKOt_TwhvWZ0NphyTW2G3otEJOQMm1hBSblAf1eyxyD8KjmTDtwAp2ZQrHZ4BplfST9nhNV9MWGzF_3EipIoW96XW0BqvWb7yB9Mx8ogzxQ9S_RorZhecwS1PvqPjitryuhnYf9b7A59RTSduuCECf38_71uXFInlIW7uKlTjmB3WpGkHQLAPs2lGB_1cmSmnHSA3iiPK2fcfeqOWphntXDQZHrGu6MeApEt0rjhVa-hmdGXMBmnuY7ybbVieGEbc8DLL2nAGzOgQ13SWAJhG2k7pyHv0ZsaX17egKOYmsW7cK69z-M4UiiKSZOBLJ9L-NLl3-bf1EEa7F21NkZAEchHjc5iyraR4UUJrS1EveC43XxHB6RPF8r0PFY8SmPmnxnFeYcJErxQ7P4Ghyr_2GGEU4u1vuZiBZeCAq-LTq_JIiCwGtvMfQWd5qj8FyzG9ZDhha2fNQyuVbb8iChngKsL73HCsqSZjQXP5DYKnP-dOS2y_Qmzxr96mr7HbNryQbWWSQG1CLbJkQ4=w178-h148-no)
![alt tag] (https://lh3.googleusercontent.com/78bt-c176Txd7bm4Nz2yojaAHAw97gN9W5iFAnkRvjkOjSsCRXUiESfwss9_3kojTE8Ce_cQkx70HnpNrJhuLtpWzuew5-fucaVW07IEtMcnmCFi-ppPpVV6LBJctdJSjogLWB6KYAJUO15FE98AMuLoPj-JUr5kEpLzrI5sHBB3UJmMPZgGno0L-yTPkl73OjsNrwIucj52tZXRPp6eWAFQxjnz9pXms3xeGxgw0b_GUFOt8KYd3IdfLWXm_d-UU_E3HlVYUQ-vu4UBShyo6nlOKDgXt2f8EPGqq03Asr05Rwgh8a13kAKDGutnaQ6F0jwY73Mk3IYVt19wpFOnIwnxIc7pV6IQoXPgm8ADk1AVHQWgO8Hz5q3F2BvGoJKgJcMZJoMgUow1J1TzkGSisULSHCI4c0TxfzM7rlvmbb6kR0Os1Di6yPutNHAcwUumD-YxcS3jlCA94NqSwCHvXjAY19UOHm3nUA-tdyFuETKJeYQMPUA0aVdVGH_MBDOvn_j1BwUBHQvfcPLYFF_v8XqktXMXr85I0DIDErbEqiHPIQSFkiZfAqCQGDnuXmKRZ0Y=s149-no)
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
![alt tag](https://lh3.googleusercontent.com/Ic6DW7CyfPptlabi4T5uRjwDoJ2TcQmZLPK88nW6I9211Vb7YOsmysl4cZFAhzoVgwr7IgvvA6v3HuZbmmV_BhgX1fyvU89e4b7c914lTZHBW4cL5OxTh3l8ubzyQ04ruxLYwyfF5VxUh9eKrOMn09oze51_dBAhxfcemrTG00jmG6jXqwU5gvC-25DSlJRXiJDeZco7Pp-n_BPgzMRllxc_F7NY5VdB9amK3Gr6tBWpynjys9LUtU2i9zq_m0c2_haIJDPFVO4686vd4bpP7gljG9VgNbahELTScIxeKHE27RDev__e0Qw01I3uqk8zJBNmkiVBbfNkRFphMecKRRk8VmFLCz9NlTe8PDAaY_XDeXsLg9CewEinJyMSVhjfoFh36mYc58XLmQl1y6Di9MIoHk_M1Iio8ExEOY3BTtY1u61sZ8WELFt1JuUWlFtewfsUz0muILy428OKg865VI44zRUXGezqkNlQCvE7O1_R4qHdEOm_cXTJbCNf3q-G3fh1BmRipTIdFZaou9f2rOoGX4y9BFr8HUadkSFSmmlm0u1OVbwv2zpR3Vbf5eiQEoM=w978-h514-no)
