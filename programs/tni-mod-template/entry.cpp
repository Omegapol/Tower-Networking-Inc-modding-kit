#include <api.hpp>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type-c-linkage"

/*
TNI modding template

https://libriscv.no/docs/host_langs/godot_integration/godot_docs/cppexamples/
https://libriscv.no/docs/host_langs/godot_integration/godot_docs/cppapi

none of the functions here should be void functions. they should all return a Variant (use Nil for no return value)

*/

static int somevar = 0;

void print_scenario_name(Object& modding_api) {
	// sample function to demonstrate usage of the game API
	Variant v = modding_api.call("get_game_world");
	if (v == Nil) return;

    Node gw(v);
    String scenario_name = gw.get("scenario_name");
    print("scenario ", scenario_name);
}

static Variant on_engine_load(Object modding_api) {
	// this is called when the engine just loaded this mod.
	print("Hello from a TNI mod, ", somevar);
	somevar += 1;
	return Nil;
}

static Variant on_game_tick(Object modding_api, double delta) {
	// this is called every game tick.
	return Nil;
}

static Variant on_player_input(Object modding_api, InputEvent event) {
	// this is called when player input is received.
    if (event.get_class() == "InputEventKey") {
        InputEventKey* key = reinterpret_cast<InputEventKey*>(&event);
        
        if (key->is_pressed() && key->get_keycode() == 32) {
            print("SPACEEEE! ", somevar);
            somevar += 1;

			print_scenario_name(modding_api);

        } else if (!key->is_pressed() && key->get_keycode() == 32) {
            print("NO SPACE :(");
        }
    }
	
	return Nil;
}

static Variant on_game_load(Object modding_api) {
	// this is called when the game is ready.
    Node gw(modding_api.call("get_game_world"));
    String scenario_name = gw.get("scenario_name");
    print("scenario ", scenario_name);
	return Nil;
}

int main() {
	// implement the following functions if you want to modify the game states
	ADD_API_FUNCTION(on_engine_load, "", "", "Called when the mod is just loaded");
	ADD_API_FUNCTION(on_game_load, "", "", "Called when the game is ready");
	ADD_API_FUNCTION(on_game_tick, "", "", "Called every game tick");
	ADD_API_FUNCTION(on_player_input, "", "", "Called when player input");

	halt();
}