/* 
 * State
 * Author: GOro
 *
 * Created on 2013. október 4., 1:30
 */

#ifndef STATE_H
#define	STATE_H

namespace sandbox { 
namespace pattern {
    
class ToolController;

// Abstract state
class Tool {
public:
    virtual void onMouseDown(ToolController*) = 0;
    virtual void onMouseUp(ToolController*) = 0;
    virtual void onMouseMove(ToolController*) = 0;
};

// Concrete state
class DrawTool : public Tool {
public:
    void onMouseDown(ToolController* controller) {
        // Implementation
    }
    void onMouseUp(ToolController* controller) {
        // Implementation
    }
    void onMouseMove(ToolController* controller) {
        // IOmplementation
    }
};

// Concrete state
class StateSelect : public Tool {
public:
    void onMouseDown(ToolController* controller) {
        // Implementation
    }
    void onMouseUp(ToolController* controller) {
        // Implementation
    }
    void onMouseMove(ToolController* controller) {
        // Implementation
    }
};

// The context which can change his state
class ToolController {
private:
    Tool* actualTool;   // actual state
    friend class Tool;  // state can invoke state transition
public:
    void onMouseDown() {
        actualTool->onMouseDown(this);
    }
    void onMouseUp() {
        actualTool->onMouseUp(this);
    }
    void onMouseMove() {
        actualTool->onMouseMove(this);
    }
};

}
}

#endif	/* STATE_H */

