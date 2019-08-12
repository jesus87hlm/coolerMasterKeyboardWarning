# coolerMasterKeyboardWarning

Trying to give utility to rgb keyboards for programming using CoolerMaster SDK to make keyboard blink


### Settings.json
<ul>
	<li>	"model" // Model ID </li>
<li>	"number_blinks" // Number of 'blinks' </li>
<li>	"reset_color" // Keyboard color after warning
	<ul>
	<li>	"r": 217,
	<li>	"g": 82,
	<li>	"b": 110
	</ul> </li>
  	<li>"effect_index" // Keyboard effect ID </li>
		</ul>
</code>

```json
{
	"model": 12,
	"number_blinks": 10,
	"reset_color": {
		"r": 217,
		"g": 82,
		"b": 110
	},
  	"effect_index": 0
}
```

### Enumeration of effects (based on SDK)

```cpp
enum EFF_INDEX { 
	EFF_FULL_ON = 0, EFF_BREATH = 1, EFF_BREATH_CYCLE = 2 , EFF_SINGLE = 3,  EFF_WAVE = 4, EFF_RIPPLE = 5, 
	EFF_CROSS = 6, EFF_RAIN = 7, EFF_STAR = 8, EFF_SNAKE = 9, EFF_REC = 10,
	EFF_SPECTRUM = 11, EFF_RAPID_FIRE = 12, EFF_INDICATOR = 13, 
	//mouse Eff
	/// New Effect
	EFF_FIRE_BALL = 14, EFF_WATER_RIPPLE = 15, EFF_REACTIVE_PUNCH = 16, 
	EFF_SNOWING = 17, 	EFF_HEART_BEAT = 18, EFF_REACTIVE_TORNADO = 19, 
	///Multi
	EFF_MULTI_1 = 0xE0, EFF_MULTI_2 = 0xE1, EFF_MULTI_3 = 0xE2, EFF_MULTI_4 = 0xE3, 	                      
	EFF_OFF = 0xFE
};

```					


### Enumeration of device list (based on SDK)

```cpp
enum DEVICE_INDEX { 
	DEV_MKeys_L = 0, DEV_MKeys_S = 1, DEV_MKeys_L_White = 2, DEV_MKeys_M_White = 3, 
	DEV_MMouse_L = 4, DEV_MMouse_S = 5, DEV_MKeys_M = 6, DEV_MKeys_S_White = 7, 
	DEV_MM520 = 8, DEV_MM530 = 9, DEV_MK750 = 10, DEV_CK372 = 11, 
	DEV_CK550_552 = 12, DEV_CK551 = 13, DEV_MM830 = 14, DEV_CK530 = 15,
	DEV_MK850 = 16,
	DEV_DEFAULT = 0xFFFF
};
```
