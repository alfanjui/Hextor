// ----------------------------------------------------------------------------|
// The definitions at this source file are not explicitly platform dependent.  |
// If you happen to find an error (most probably in the way the code interacts |
// with the Windows® OS's DLLs) PLEASE create an "issue" at					   |
// https://github.com/alfanjui/hextor										   |
// ----------------------------------------------------------------------------|

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "../include/glad.h"
#include "../include/GLFW/glfw3.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void HelpMarker(const char* desc);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

	// ImGui context setup
	// -------------------
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO(); (void)io;		

	// Bindings
	// --------	
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 460");
	ImGui::StyleColorsDark();

    
    bool my_tool_active = true;
	
    // Render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
		glfwPollEvents();
		
        // Render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		// ImGui
		// -----
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		//ImGui::SetNextItemWidth(100.0f);
		//ImGui::SetNextWindowPos(0.0f, 0.0f);
		//ImGui::SetNextWindowSize();
		ImGui::Begin("Hexno", &my_tool_active, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
		//io -> DisplaySize.x;
		//io -> DisplaySize.y;

		if (ImGui::BeginMenuBar())
		{
		    if (ImGui::BeginMenu("File"))       
			{
				if (ImGui::MenuItem("Open ...", "Ctrl+O")) { /* Event */	}
				if (ImGui::MenuItem("Close", "Ctrl+W")) { my_tool_active = false; }
				ImGui::EndMenu();
		    }
		    ImGui::EndMenuBar();
		}

		// Tabs
		// ----
		static bool show_trailing_button = true;
        static const char* fileNames = {};

		ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
		if (ImGui::BeginTabBar("Open Files", tab_bar_flags))
		{
		    for(int n = 0, n < 
		    if (ImGui::BeginTabItem("file1"))
		    {
	            ImGui::Text("file1 hexdump content");
				ImGui::EndTabItem();
			}
		}
		ImGui::EndTabBar();

		// Hex representation
		// ------------------
		static int ShowMode;
		ImGui::Text("hex text"); // Pass the result of hexdump	
		ImGui::Separator();
		ImGui::Text("Hex rep");
		ImGui::Separator();
		if (ImGui::RadioButton("ASCII", ShowMode == 0)) { ShowMode = 0; }
		ImGui::SameLine();
		if (ImGui::RadioButton("UTF-8", ShowMode == 1)) { ShowMode = 1; }
		ImGui::SameLine();
		HelpMarker("Change the character representation of the hex dump");

		ImGui::End();

		ImGui::ShowDemoWindow();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


// Helper Functions built upon ImGui widgets
// -----------------------------------------

void HelpMarker(const char* desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}
