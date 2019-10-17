//
// Created by 王存俊 on 2019/10/13.
//

enum class Color {
	red, blue, green
};

enum class TrafficLight {
	green, yellow, red
};

Color col = Color::red;
TrafficLight light = TrafficLight::red;

// prefix increment ++
TrafficLight &operator++(TrafficLight &t) {
	switch (t) {
		case TrafficLight::green:
			return t = TrafficLight::yellow;
		case TrafficLight::yellow:
			return t = TrafficLight::res;
		case TrafficLight::red:
			return t = TrafficLight::green;
	}
}

TrafficLight next = ++light;