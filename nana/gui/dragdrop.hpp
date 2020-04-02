/**
*	Drag and Drop Implementation
*	Nana C++ Library(http://www.nanapro.org)
*	Copyright(C) 2018-2019 Jinhao(cnjinhao@hotmail.com)
*
*	Distributed under the Boost Software License, Version 1.0.
*	(See accompanying file LICENSE_1_0.txt or copy at
*	http://www.boost.org/LICENSE_1_0.txt)
*
*	@file: nana/gui/dragdrop.hpp
*	@author: Jinhao(cnjinhao@hotmail.com)
*/
#ifndef NANA_GUI_DRAGDROP_INCLUDED
#define NANA_GUI_DRAGDROP_INCLUDED

#include <nana/push_ignore_diagnostic>
#include <functional>
#include "basis.hpp"

#include <memory>
#include <nana/filesystem/filesystem.hpp>

namespace nana
{
	/// Drag and drop actions
	enum class dnd_action
	{
		copy,	///< Copy the data to target.
		move, 	///< Move the data to target.
		link	///< Create a link from source data to target.
	};

	class simple_dragdrop
	{
		struct implementation;

		simple_dragdrop(const simple_dragdrop&) = delete;
		simple_dragdrop& operator=(const simple_dragdrop&) = delete;

		simple_dragdrop(simple_dragdrop&&) = delete;
		simple_dragdrop& operator=(simple_dragdrop&&) = delete;
	public:
		explicit simple_dragdrop(window source);
		simple_dragdrop(window                drag_origin,
						std::function<bool()> when,
						window                drop_target,
						std::function<void()> how)
		: simple_dragdrop{drag_origin}
		{
			condition(when);
			make_drop(drop_target, how);
		}
		~simple_dragdrop();

		/// Condition checker
		/**
		 * Sets a condition checker that determines whether the drag-and-drop operation can start. If a condition checker is not set, it always start drag-and-drop operation.
		 * @param predicate_fn Unary predicate which returns #true# for starting drag-and-drop operation.
		 */
		void condition(std::function<bool()> predicate_fn);
		void make_drop(window target, std::function<void()> drop_fn);
	private:
		implementation* const impl_;
	};

	namespace detail
	{
		struct dragdrop_data;
	}

	class dragdrop
	{
		struct implementation;

		/// Non-copyable
		dragdrop(const dragdrop&) = delete;
		dragdrop& operator=(const dragdrop&) = delete;

		/// Non-movable
		dragdrop(dragdrop&&) = delete;
		dragdrop& operator=(dragdrop&&) = delete;
	public:
		class data
		{
			friend struct dragdrop::implementation;

			/// Non-copyable
			data(const data&) = delete;
			data& operator=(const data&) = delete;
		public:
			/// Constructor
			/**
			 * Constructs a data object used for drag and drop
			 * @param requested_action Indicates how the data to be transferred.
			 */
			data(dnd_action requested_action = dnd_action::copy);
			data(data&&);
			~data();

			data& operator=(data&& rhs);

			void insert(std::filesystem::path);
		private:
			detail::dragdrop_data* real_data_;
		};

		dragdrop(window source);
		~dragdrop();

		/// Condition checker
		/***
		 * Sets a condition checker that determines whether the drag-and-drop operation can start. If a condition checker is not set, it always start drag-and-drop operation.
		 * @param predicate_fn A predicate function to be set.
		 */
		void condition(std::function<bool()> predicate_fn);

		/// Transferred data
		/**
		 * Set a data generator. When drag begins, it is called to generate a data object for transferring.
		 * @param generator It returns the data for transferring.
		 */
		void prepare_data(std::function<data()> generator);

		/// Drop handler
		/**
		 * The drop handler is called when the drop operation is completed. There are 3 parameters for the handler
		 *		dropped Indicates whether the data is accepted by a target window.
		 *		executed_action Indicates the action returned by target window. Ignore if dropped is false.
		 *		data_transferred The data object which is generated by the generator.
		 * @param finish_fn The drop handling function.
		 */
		void drop_finished(std::function<void(bool dropped, dnd_action executed_action, data& data_transferred)> finish_fn);
	private:
		implementation* const impl_;
	};
}

#endif