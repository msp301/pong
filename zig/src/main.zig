const std = @import("std");

const c = @cImport({
    @cInclude("SDL.h");
    @cInclude("SDL_image.h");
});

pub fn main() !void {
    if (c.SDL_Init(c.SDL_INIT_EVERYTHING) != 0) {
        std.debug.print("Error initialising SDL: {s}", .{c.SDL_GetError()});
        return;
    }

    defer c.SDL_Quit();

    const windowHeight = 800;
    const windowWidth = 600;
    const window = c.SDL_CreateWindow(null, c.SDL_WINDOWPOS_CENTERED, c.SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, c.SDL_WINDOW_BORDERLESS) orelse {
        std.debug.print("Error creating SDL window: {s}", .{c.SDL_GetError()});
        return;
    };

    const renderer = c.SDL_CreateRenderer(window, -1, c.SDL_RENDERER_ACCELERATED) orelse {
        std.debug.print("Error creating SDL renderer: {s}", .{c.SDL_GetError()});
        return;
    };

    _ = c.SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    _ = c.SDL_RenderClear(renderer);

    c.SDL_RenderPresent(renderer);

    //TODO: Make an actual game loop
    while (true) {}
}

test "simple test" {
    var list = std.ArrayList(i32).init(std.testing.allocator);
    defer list.deinit(); // try commenting this out and see if zig detects the memory leak!
    try list.append(42);
    try std.testing.expectEqual(@as(i32, 42), list.pop());
}
