#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	float radius = 45;
	float len = 10;
	bool flag = true;
	ofColor color;

	for (int x = -288; x <= 288; x += 144) {

		for (int y = -288; y <= 288; y += 144) {

			ofPushMatrix();
			ofTranslate(x, y);

			flag = !flag;

			for (int i = 0; i < 4; i++) {

				len = ofMap(i, 0, 3, 2, 18);

				vector<glm::vec2> vertices_1, vertices_2;
				float deg_start = ofRandom(360) + ofGetFrameNum() * ofRandom(3, 10) * (flag ? 1 : -1);

				for (float deg = deg_start; deg < deg_start + 90; deg += 1) {

					vertices_1.push_back(glm::vec2((radius - len * 0.5) * cos(deg * DEG_TO_RAD), (radius - len * 0.5) * sin(deg * DEG_TO_RAD)));
					vertices_2.push_back(glm::vec2((radius + len * 0.5) * cos(deg * DEG_TO_RAD), (radius + len * 0.5) * sin(deg * DEG_TO_RAD)));
				}

				reverse(vertices_2.begin(), vertices_2.end());

				ofNoFill();
				ofSetColor(0);
				ofSetLineWidth(1);

				ofBeginShape();
				ofVertices(vertices_1);
				ofVertices(vertices_2);
				ofEndShape(true);

				if (i == 0) {

					ofFill();

					ofBeginShape();
					ofVertices(vertices_1);
					ofVertices(vertices_2);
					ofEndShape(true);
				}

				if (i == 2) {

					color.setHsb(ofRandom(255), 255, 200);
					ofSetColor(color);
					ofSetLineWidth(2);

					ofBeginShape();
					ofVertices(vertices_1);
					ofVertices(vertices_2);
					ofEndShape(true);
				}
			}

			ofPopMatrix();
		}
	}

	/*
	int start = 1;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}