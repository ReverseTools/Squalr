// Copyright (c) 2014-2015 Wolfgang Borgsmüller
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
// 1. Redistributions of source code must retain the above copyright 
//    notice, this list of conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright 
//    notice, this list of conditions and the following disclaimer in the 
//    documentation and/or other materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its 
//    contributors may be used to endorse or promote products derived 
//    from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
// COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS 
// OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND 
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR 
// TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE 
// USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// Generated file. Do not edit.


// cef_dialog_handler

typedef struct _cfx_dialog_handler_t {
    cef_dialog_handler_t cef_dialog_handler;
    unsigned int ref_count;
    gc_handle_t gc_handle;
    int wrapper_kind;
    // managed callbacks
    void (CEF_CALLBACK *on_file_dialog)(gc_handle_t self, int* __retval, cef_browser_t* browser, int *browser_release, cef_file_dialog_mode_t mode, char16 *title_str, int title_length, char16 *default_file_path_str, int default_file_path_length, cef_string_list_t accept_filters, int selected_accept_filter, cef_file_dialog_callback_t* callback, int *callback_release);
} cfx_dialog_handler_t;

void CEF_CALLBACK _cfx_dialog_handler_add_ref(struct _cef_base_t* base) {
    InterlockedIncrement(&((cfx_dialog_handler_t*)base)->ref_count);
}
int CEF_CALLBACK _cfx_dialog_handler_release(struct _cef_base_t* base) {
    int count = InterlockedDecrement(&((cfx_dialog_handler_t*)base)->ref_count);
    if(count == 0) {
        if(((cfx_dialog_handler_t*)base)->wrapper_kind == 0) {
            cfx_gc_handle_free(((cfx_dialog_handler_t*)base)->gc_handle);
        } else {
            cfx_gc_handle_free_remote(((cfx_dialog_handler_t*)base)->gc_handle);
        }
        free(base);
        return 1;
    }
    return 0;
}
int CEF_CALLBACK _cfx_dialog_handler_has_one_ref(struct _cef_base_t* base) {
    return ((cfx_dialog_handler_t*)base)->ref_count == 1 ? 1 : 0;
}

static cfx_dialog_handler_t* cfx_dialog_handler_ctor(gc_handle_t gc_handle, int wrapper_kind) {
    cfx_dialog_handler_t* ptr = (cfx_dialog_handler_t*)calloc(1, sizeof(cfx_dialog_handler_t));
    if(!ptr) return 0;
    ptr->cef_dialog_handler.base.size = sizeof(cef_dialog_handler_t);
    ptr->cef_dialog_handler.base.add_ref = _cfx_dialog_handler_add_ref;
    ptr->cef_dialog_handler.base.release = _cfx_dialog_handler_release;
    ptr->cef_dialog_handler.base.has_one_ref = _cfx_dialog_handler_has_one_ref;
    ptr->ref_count = 1;
    ptr->gc_handle = gc_handle;
    ptr->wrapper_kind = wrapper_kind;
    return ptr;
}

static gc_handle_t cfx_dialog_handler_get_gc_handle(cfx_dialog_handler_t* self) {
    return self->gc_handle;
}

// on_file_dialog

int CEF_CALLBACK cfx_dialog_handler_on_file_dialog(cef_dialog_handler_t* self, cef_browser_t* browser, cef_file_dialog_mode_t mode, const cef_string_t* title, const cef_string_t* default_file_path, cef_string_list_t accept_filters, int selected_accept_filter, cef_file_dialog_callback_t* callback) {
    int __retval;
    int browser_release;
    int callback_release;
    ((cfx_dialog_handler_t*)self)->on_file_dialog(((cfx_dialog_handler_t*)self)->gc_handle, &__retval, browser, &browser_release, mode, title ? title->str : 0, title ? (int)title->length : 0, default_file_path ? default_file_path->str : 0, default_file_path ? (int)default_file_path->length : 0, accept_filters, selected_accept_filter, callback, &callback_release);
    if(browser_release) browser->base.release((cef_base_t*)browser);
    if(callback_release) callback->base.release((cef_base_t*)callback);
    return __retval;
}

static void cfx_dialog_handler_set_callback(cef_dialog_handler_t* self, int index, void* callback) {
    switch(index) {
    case 0:
        ((cfx_dialog_handler_t*)self)->on_file_dialog = (void (CEF_CALLBACK *)(gc_handle_t self, int* __retval, cef_browser_t* browser, int *browser_release, cef_file_dialog_mode_t mode, char16 *title_str, int title_length, char16 *default_file_path_str, int default_file_path_length, cef_string_list_t accept_filters, int selected_accept_filter, cef_file_dialog_callback_t* callback, int *callback_release))callback;
        self->on_file_dialog = callback ? cfx_dialog_handler_on_file_dialog : 0;
        break;
    }
}
