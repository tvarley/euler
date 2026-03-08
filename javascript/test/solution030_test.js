var assert = require('assert');
var solution030 = require('../src/euler/solution030');

describe('Solution030', function() {
  describe('answer', function() {
    it('will answer problem 030', function() {
      assert.equal(solution030.answer(), 443839);
    });
  });
});
