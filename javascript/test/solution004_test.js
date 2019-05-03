var assert = require('assert');
var solution004 = require('../src/euler/solution004');

describe('Solution004', function() {
  describe('answer', function() {
    it('will answer problem 004', function() {
      assert.equal(solution004.answer(), 906609);
    });
  });
});
