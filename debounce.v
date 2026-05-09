module debounce(
	input rst_n,
	input clk,
	input key,
	input EdgeMode,
	output reg press
);

reg [18:0]ticks;
reg ctrl;

reg sync_key0;
reg sync_key1;
reg previous_state;

always @(posedge clk or negedge rst_n) begin
	if(!rst_n) begin
		previous_state <= 0;
		sync_key0 <= 0;
		sync_key1 <= 0;
	end else begin
		sync_key0 <= key;
		sync_key1 <= sync_key0;
		previous_state <= sync_key1;
	end
end


always @(posedge clk or negedge rst_n) begin
	if(!rst_n) begin
		press <= 1'b0;
	end else begin
		if(!ctrl) begin
			case(EdgeMode)
				0:begin
					press <= ((previous_state) & (~sync_key1))? 1'b1:1'b0;
				end
				1:begin
					press <= ((~previous_state) & (sync_key1))? 1'b1:1'b0;
				end
				default:;
			endcase
		end else begin
			press <= 1'b0;
		end
	end
end


always @(posedge clk or negedge rst_n) begin
	if(!rst_n) begin
		ticks <= 0;
		ctrl <= 1'b0;
	end else begin
		if(press) begin
			ctrl <= 1'b1;
		end
		if(ctrl) begin
			ticks <= ticks + 1;
			if(ticks >= 19'd500_000) begin
				ticks <= 0;
				ctrl <= 0;
			end
		end
	end
end

endmodule 